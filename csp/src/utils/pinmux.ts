export interface PinAssignment {
  function?: string
  locked?: boolean
}

export interface SignalRequest {
  signal: string
  pins: string[]
}

/** Find a complete assignment before changing any pins. Locked pins are never moved. */
export function allocateSignals(requests: SignalRequest[], current: Record<string, PinAssignment>) {
  const assignments: Record<string, string> = {}
  const owners = new Map<string, string>()
  const candidates = new Map(requests.map(request => [request.signal, [...new Set(request.pins)]]))
  const fixed = new Set<string>()
  const conflicts = new Set<string>()

  for (const [pin, config] of Object.entries(current)) {
    if (config.locked && config.function) {
      owners.set(pin, config.function)
      fixed.add(pin)
      if (candidates.get(config.function)?.includes(pin)) {
        if (assignments[config.function])
          conflicts.add(config.function)
        assignments[config.function] = pin
      }
    }
  }

  function assign(signal: string, visited: Set<string>): boolean {
    const pins = [...(candidates.get(signal) ?? [])].sort((a, b) =>
      Number(current[b]?.function === signal) - Number(current[a]?.function === signal))
    for (const pin of pins) {
      if (visited.has(pin) || fixed.has(pin))
        continue
      visited.add(pin)
      const owner = owners.get(pin)
      if (!owner || assign(owner, visited)) {
        owners.set(pin, signal)
        assignments[signal] = pin
        return true
      }
    }
    return false
  }

  for (const signal of candidates.keys()) {
    if (!assignments[signal] && !assign(signal, new Set()))
      conflicts.add(signal)
  }
  return { assignments, conflicts: [...conflicts], success: conflicts.size === 0 }
}

export function pathsOverlap(first: string, second: string): boolean {
  return first === second || first.startsWith(`${second}.`) || second.startsWith(`${first}.`)
}
