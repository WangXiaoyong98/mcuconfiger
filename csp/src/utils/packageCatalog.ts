import type { PackageIndexType } from './packages'
import semver from 'semver'

export interface PackageSelection {
  kind: string
  name: string
  version: string
}

export interface PackageTreeNode {
  key: string
  label: string
  type: 'type' | 'name' | 'version'
  selection?: PackageSelection
  children?: PackageTreeNode[]
}

export function packageKey(selection: PackageSelection): string {
  return JSON.stringify([selection.kind, selection.name, selection.version])
}

export function comparePackageVersions(a: string, b: string): number {
  if (a === b)
    return 0
  if (a === 'latest')
    return -1
  if (b === 'latest')
    return 1
  if (semver.valid(a) && semver.valid(b))
    return semver.rcompare(a, b)
  return b.localeCompare(a, undefined, { numeric: true })
}

export function buildPackageTree(index: PackageIndexType, query = '', filterKind = ''): PackageTreeNode[] {
  const terms = query.trim().toLowerCase().split(/\s+/).filter(Boolean)
  const result: PackageTreeNode[] = []
  for (const kind of Object.keys(index).sort()) {
    if (filterKind && filterKind !== kind)
      continue
    const names: PackageTreeNode[] = []
    for (const name of Object.keys(index[kind]).sort((a, b) => a.localeCompare(b))) {
      const versions = Object.keys(index[kind][name]).sort(comparePackageVersions).filter(version => terms.every(term => `${kind} ${name} ${version}`.toLowerCase().includes(term))).map((version): PackageTreeNode => {
        const selection = { kind, name, version }
        return { key: packageKey(selection), label: version, type: 'version', selection }
      })
      if (versions.length)
        names.push({ key: JSON.stringify([kind, name]), label: name, type: 'name', children: versions })
    }
    if (names.length)
      result.push({ key: JSON.stringify([kind]), label: kind, type: 'type', children: names })
  }
  return result
}
