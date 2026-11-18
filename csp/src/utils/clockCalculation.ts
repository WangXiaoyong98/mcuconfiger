export interface ClockInput {
  type: string
  value: string | number | boolean
  enabled: boolean
  options?: Record<string, boolean>
  min?: number
  max?: number
}

export interface ClockConnection {
  source: string
  target: string
  targetHandle?: string | null
}

export interface ClockIssue {
  node: string
  reason: 'missingParameter' | 'missingInput' | 'multipleInputs' | 'cycle' | 'invalidValue' | 'disabledSource' | 'outOfRange'
}

/** Evaluate the selected clock paths independently of the rendered diagram. */
export function calculateClocks(nodes: Record<string, ClockInput>, edges: ClockConnection[]) {
  const outputs: Record<string, number> = {}
  const issues: ClockIssue[] = []
  const visiting = new Set<string>()
  const incoming = new Map<string, ClockConnection[]>()
  for (const edge of edges)
    incoming.set(edge.target, [...(incoming.get(edge.target) ?? []), edge])

  function problem(node: string, reason: ClockIssue['reason']) {
    if (!issues.some(issue => issue.node === node && issue.reason === reason))
      issues.push({ node, reason })
    return 0
  }

  function evaluate(name: string): number {
    if (name in outputs)
      return outputs[name]
    if (visiting.has(name))
      return problem(name, 'cycle')
    const node = nodes[name]
    if (!node)
      return problem(name, 'missingParameter')
    visiting.add(name)
    let output = 0
    // Outputs/probes can be read-only monitors with enabled=false in existing databases.
    const monitor = ['ct-output', 'ct-probe'].includes(node.type)
    if (!node.enabled && !monitor) {
      output = 0
    }
    else if (['ct-input-number', 'ct-number-label'].includes(node.type)) {
      output = Number(node.value)
    }
    else {
      let inputs = incoming.get(name) ?? []
      if (node.type === 'ct-radio') {
        inputs = inputs.filter(edge => edge.targetHandle === `target-${node.value}`)
        if (!node.options || !(String(node.value) in node.options))
          problem(name, 'invalidValue')
        else if (!node.options[String(node.value)])
          problem(name, 'disabledSource')
      }
      if (inputs.length !== 1) {
        problem(name, inputs.length ? 'multipleInputs' : 'missingInput')
      }
      else {
        output = evaluate(inputs[0].source)
        if (node.type === 'ct-radio' && !node.options?.[String(node.value)])
          output = 0
        if (node.type === 'ct-select') {
          const match = /^([+*/-])(\d+(?:\.\d+)?)$/.exec(String(node.value))
          if (!match || node.options?.[String(node.value)] === false) {
            output = problem(name, 'invalidValue')
          }
          else {
            const operand = Number(match[2])
            switch (match[1]) {
              case '+': output += operand
                break
              case '-': output -= operand
                break
              case '*': output *= operand
                break
              case '/': output /= operand
                break
            }
          }
        }
      }
    }
    if (!Number.isFinite(output) || output < 0)
      output = problem(name, 'invalidValue')
    if (output > 0 && (output < (node.min ?? 0) || output > (node.max ?? Number.MAX_VALUE)))
      problem(name, 'outOfRange')
    visiting.delete(name)
    outputs[name] = output
    return output
  }

  for (const name of Object.keys(nodes))
    evaluate(name)
  return { outputs, issues }
}
