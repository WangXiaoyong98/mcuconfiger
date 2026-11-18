/* eslint-disable no-template-curly-in-string -- These are database placeholders, not JavaScript interpolation. */
import type { IpType, ProjectType, SummaryType } from '../electron/types'
import type { ClockInput } from '../src/utils/clockCalculation'
import assert from 'node:assert/strict'
import { readFileSync } from 'node:fs'
import { it } from 'node:test'
import { computed, effectScope, nextTick, ref } from 'vue'
import { parse } from 'yaml'
import { ClockTree } from '../src/database/clockTree'
import { Ip, IpManager, isEnumParameter } from '../src/database/ip'
import { Summary } from '../src/database/summary'
import { calculateClocks } from '../src/utils/clockCalculation'
import { allocateSignals, pathsOverlap } from '../src/utils/pinmux'
import { Pin, PinsManager } from '../src/utils/pins'
import { Project, ProjectConfigs } from '../src/utils/project'

function yaml(path: string) {
  return parse(readFileSync(new URL(`../resources/database/${path}`, import.meta.url), 'utf8'))
}

function fixture(configs: Record<string, any> = {}) {
  const locale = ref('en')
  const summary = new Summary(yaml('summary/StarPower/SP28038.yml') as SummaryType, computed({ get: () => locale.value, set: value => locale.value = value }))
  const project = new Project({ version: '0.1.2', name: 'test', vendor: 'StarPower', targetChip: 'SP28038', modules: [], configs, gen: {} } as ProjectType, 'test.csp')
  return { project, summary, locale: summary.locale }
}

// Project dirty-state tracking changes the title; no Electron UI is needed here.
Object.defineProperty(globalThis, 'document', { configurable: true, value: { title: '' } })

it('allocates alternate pins with backtracking and preserves locked assignments', () => {
  const requests = [{ signal: 'TX', pins: ['P1', 'P2'] }, { signal: 'RX', pins: ['P1'] }]
  assert.deepEqual(allocateSignals(requests, {}).assignments, { TX: 'P2', RX: 'P1' })
  assert.equal(allocateSignals(requests, { P1: { function: 'GPIO', locked: true } }).success, false)
  assert.deepEqual(allocateSignals(requests, { P2: { function: 'TX', locked: true } }).assignments, { TX: 'P2', RX: 'P1' })
  assert.equal(allocateSignals([{ signal: 'TX', pins: [] }], {}).success, false)
})

it('pin conflicts distinguish missing mappings and duplicate locked signals', () => {
  assert.deepEqual(allocateSignals([{ signal: 'TX', pins: ['P1', 'P2'] }], {
    P1: { function: 'TX', locked: true },
    P2: { function: 'TX', locked: true },
  }).conflicts, ['TX'])
})

it('configuration paths match ancestors without confusing USART1 and USART10', () => {
  assert.equal(pathsOverlap('configs.USART1', 'configs.USART1.mode'), true)
  assert.equal(pathsOverlap('configs.USART10', 'configs.USART1'), false)
  const configs = new ProjectConfigs({ GPIO: null })
  assert.equal(configs.get('GPIO.P1.mode', 'input'), 'input')
  configs.set('GPIO.P1.mode', 'output')
  assert.equal(configs.get('GPIO.P1.mode'), 'output')
})

it('clock mux, PLL, divider and output follow the selected path', () => {
  const nodes: Record<string, ClockInput> = {
    hsi: { type: 'ct-input-number', value: 8000000, enabled: true },
    hse: { type: 'ct-input-number', value: 12000000, enabled: true },
    mux: { type: 'ct-radio', value: 'hse', enabled: true, options: { hsi: true, hse: true } },
    pll: { type: 'ct-select', value: '*6', enabled: true },
    bus: { type: 'ct-select', value: '/2', enabled: true },
    out: { type: 'ct-output', value: 0, enabled: false, max: 40000000 },
  }
  const edges = [
    { source: 'hsi', target: 'mux', targetHandle: 'target-hsi' },
    { source: 'hse', target: 'mux', targetHandle: 'target-hse' },
    { source: 'mux', target: 'pll' },
    { source: 'pll', target: 'bus' },
    { source: 'bus', target: 'out' },
  ]
  assert.equal(calculateClocks(nodes, edges).outputs.out, 36000000)
  nodes.mux.value = 'hsi'
  assert.equal(calculateClocks(nodes, edges).outputs.out, 24000000)
  nodes.hsi.enabled = false
  nodes.mux.options!.hsi = false
  const result = calculateClocks(nodes, edges)
  assert.equal(result.outputs.out, 0)
  assert.ok(result.issues.some(issue => issue.reason === 'disabledSource'))
})

it('invalid clock paths report cycles, divide by zero and out-of-range outputs', () => {
  const nodes = {
    a: { type: 'ct-probe', value: 0, enabled: true },
    b: { type: 'ct-select', value: '/0', enabled: true },
  }
  const result = calculateClocks(nodes, [{ source: 'a', target: 'b' }, { source: 'b', target: 'a' }])
  assert.ok(result.issues.some(issue => issue.reason === 'cycle'))
  assert.ok(result.issues.some(issue => issue.reason === 'invalidValue'))
  assert.ok(Object.values(result.outputs).every(Number.isFinite))
  assert.equal(calculateClocks({ input: { type: 'ct-input-number', value: 100, enabled: true, max: 50 } }, []).issues[0].reason, 'outOfRange')
})

it('real chip clocks update and persist without mounting ClockView', async () => {
  const scope = effectScope()
  await scope.run(async () => {
    const { project, summary, locale } = fixture()
    assert.ok(summary.moduleList.GPIO)
    assert.ok(summary.moduleList.USART1)
    const ip = new Ip('RCM', yaml('ip/peripherals/StarPower/sp28038_rcm.yml'), project, locale, summary)
    const tree = new ClockTree(yaml('clock/StarPower/SP28038.yml'), ip)
    await nextTick()
    assert.equal(tree.calculation.value.outputs.rcm_hclk_t, 8000000)
    assert.equal(tree.calculation.value.outputs.rcm_hsi_clk_div_pll_t, 4000000)
    assert.deepEqual(tree.calculation.value.issues, [])
    project.configs.set('RCM.rcm_ahb_clk_div_hclk_t', '/2')
    await nextTick()
    assert.equal(tree.calculation.value.outputs.rcm_hclk_t, 4000000)
    assert.equal(project.configs.get('RCM.rcm_hclk_t'), 4000000)
    const restored = fixture(JSON.parse(JSON.stringify(project.origin.configs)))
    const restoredIp = new Ip('RCM', yaml('ip/peripherals/StarPower/sp28038_rcm.yml'), restored.project, restored.locale, restored.summary)
    const restoredTree = new ClockTree(yaml('clock/StarPower/SP28038.yml'), restoredIp)
    await nextTick()
    assert.equal(restoredTree.calculation.value.outputs.rcm_hclk_t, 4000000)
  })
  scope.stop()
})

it('GPIO defaults, direction changes, labels, locks and alternate functions persist', async () => {
  const scope = effectScope()
  await scope.run(async () => {
    const { project, summary, locale } = fixture()
    const ip = new Ip('GPIO', yaml('ip/peripherals/StarPower/sp28038_gpio.yml'), project, locale, summary)
    const pin = new Pin('GPIO22', summary.pins.GPIO22, ip)
    const manager = new PinsManager()
    manager.pins.GPIO22 = pin
    assert.equal(manager.assign('GPIO22', 'GPIO:22'), null)
    await nextTick()
    assert.equal(project.configs.get('GPIO.GPIO22.gpio_pin_type_t'), 'pullup')
    assert.equal(manager.assign('GPIO22', 'SCI3_TX:Y'), 'locked')
    pin.locked.value = false
    assert.equal(manager.assign('GPIO22', 'SCI3_TX:Y'), null)
    pin.label.value = 'TX'
    project.configs.set('GPIO.GPIO22.gpio_direction_t', 'output')
    await nextTick()
    assert.equal(project.configs.get('GPIO.GPIO22.gpio_pin_type_t'), 'push_pull')
    assert.ok(Object.keys(pin.refParameters.value).length > 0)
    const restored = fixture(JSON.parse(JSON.stringify(project.origin.configs)))
    const restoredPin = new Pin('GPIO22', restored.summary.pins.GPIO22, new Ip('GPIO', yaml('ip/peripherals/StarPower/sp28038_gpio.yml'), restored.project, restored.locale, restored.summary))
    assert.equal(restoredPin.function.value, 'SCI3_TX:Y')
    assert.equal(restoredPin.label.value, 'TX')
    assert.equal(restoredPin.locked.value, true)
    project.configs.set('pins', {})
    assert.equal(pin.function.value, '')
  })
  scope.stop()
})

it('peripheral conditions use the right instance and react to parent replacement', async () => {
  const scope = effectScope()
  await scope.run(async () => {
    const { project, summary, locale } = fixture({ USART1: { mode: 'on' } })
    const definition: IpType = { name: 'USART', parameters: {
      mode: { type: 'enum', default: 'off', values: { off: {}, on: {} } },
      value: [
        { condition: 'configs.${IP_INSTANCE}.mode == \'on\'', content: { type: 'integer', default: 4, max: 10 } },
        { condition: 'default', content: { type: 'integer', default: 0, max: 0 } },
      ],
      enabled: { type: 'boolean', default: false, enabled: 'configs.${IP_INSTANCE}.mode == \'on\'' },
    } }
    const first = new Ip('USART1', definition, project, locale, summary)
    const second = new Ip('USART2', definition, project, locale, summary)
    assert.equal(first.parameters.value.value.default, 4)
    assert.equal(second.parameters.value.value.default, 0)
    assert.equal(first.parameters.enabled.value.enabled.value, true)
    assert.equal(first.getExpression('${IP_SUFFIXED}'), '1')
    project.configs.set('USART1', { mode: 'off' })
    await nextTick()
    assert.equal(first.parameters.value.value.default, 0)
    assert.equal(first.parameters.enabled.value.enabled.value, false)
  })
  scope.stop()
})

it('peripheral mode changes allocate pins and release only managed unlocked signals', async () => {
  const scope = effectScope()
  await scope.run(async () => {
    const { project, summary, locale } = fixture()
    const gpio = new Ip('GPIO', yaml('ip/peripherals/StarPower/sp28038_gpio.yml'), project, locale, summary)
    const serial = new Ip('SCI3', { name: 'SCI', parameters: {
      mode: { type: 'enum', default: 'off', values: { off: {}, on: { signals: { 'SCI3_TX:Y': { mode: 'GPIO:Output' } } } } },
    }, containers: { modes: { refParameters: { mode: {} } } } }, project, locale, summary)
    const manager = new PinsManager()
    for (const [name, pin] of Object.entries(summary.pins))
      manager.pins[name] = new Pin(name, pin, gpio)
    const ips = new IpManager()
    ips.getPeripherals = () => [gpio, serial]
    manager.init(project, summary, ips)
    project.configs.set('SCI3.mode', 'on')
    await nextTick()
    assert.equal(manager.allocation.value.success, true)
    const chosen = manager.allocation.value.assignments['SCI3_TX:Y']
    assert.equal(manager.pins[chosen].function.value, 'SCI3_TX:Y')
    assert.equal(project.configs.get(`GPIO.${chosen}.gpio_direction_t`), 'output')
    project.configs.set('SCI3.mode', 'off')
    await nextTick()
    assert.equal(manager.pins[chosen].function.value, '')
    const mode = serial.parameters.mode.value
    assert.ok(isEnumParameter(mode))
    for (const name of summary.findPinsBySignals(['SCI3_TX:Y'])) {
      manager.pins[name].setFunction(manager.pins[name].modes[0])
    }
    await nextTick()
    assert.equal(mode.values.on.valid.value.isEnabled, false)
  })
  scope.stop()
})

it('saving flushes derived clock values and keeps a stable IPC snapshot', async () => {
  const scope = effectScope()
  await scope.run(async () => {
    const { project, summary, locale } = fixture()
    const ip = new Ip('RCM', yaml('ip/peripherals/StarPower/sp28038_rcm.yml'), project, locale, summary)
    const tree = new ClockTree(yaml('clock/StarPower/SP28038.yml'), ip)
    let saved: ProjectType | undefined
    Object.defineProperty(globalThis, 'window', { configurable: true, value: {
      electron: { invoke: async (_event: string, data: ProjectType) => { saved = data } },
    } })
    project.configs.set('RCM.rcm_ahb_clk_div_hclk_t', '/4')
    await project.save()
    assert.equal(tree.calculation.value.outputs.rcm_hclk_t, 2000000)
    assert.equal(saved?.configs?.RCM.rcm_hclk_t, 2000000)
    project.configs.set('RCM.rcm_ahb_clk_div_hclk_t', '/2')
    await nextTick()
    assert.equal(saved?.configs?.RCM.rcm_hclk_t, 2000000)
    assert.equal(project.configs.get('RCM.rcm_hclk_t'), 4000000)
  })
  scope.stop()
})
