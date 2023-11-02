#!/usr/bin/env python

import sys
from heapq import heappush, heappop

def main():
  n, m, c = map(int, raw_input().split())

  keyVerts = set(map(int, raw_input().split()))

  adj = [[] for _ in xrange(n)]
  for _ in xrange(m):
    u, v, w = map(int, raw_input().split())
    adj[u].append((v, w))

  dist, keyPred = dijkstra(0, n, adj, keyVerts)
  nk, parents = makeKeyDag(keyVerts, dist, keyPred)
  trucks = countPaths(nk, parents)

  print trucks

def dijkstra(s, n, adj, keyVerts):
  # dijkstra + keeping track of "key" vertices on all shortest paths
  dist = [None] * n
  keyPred = [set() for _ in xrange(n)]
  q = []
  def tryPush(v, d, kp):
    if (dist[v] is None) or (d < dist[v]):
      heappush(q, (d, v))
      dist[v] = d
      keyPred[v] = kp.copy()
    elif d == dist[v]:
      keyPred[v] |= kp

  tryPush(s, 0, set())
  while q:
    d, u = heappop(q)
    if d == dist[u]:
      if u in keyVerts:
        kp = set([u])
      else:
        kp = keyPred[u]

      for (v, w) in adj[u]:
        tryPush(v, d+w, kp)

  return (dist, keyPred)

def makeKeyDag(keyVerts, dist, keyPred):
  # determine transitive closure of "key" vertex connections (which form a DAG)
  # process nodes in dist order, and also remap the vertex numbering

  nk = len(keyVerts)
  keyOrder = sorted(keyVerts, key=lambda v: dist[v])
  keyNum = dict((v, i) for (i, v) in enumerate(keyOrder))

  parents = [set() for _ in xrange(nk)]
  for (kv, v) in enumerate(keyOrder):
    for p in keyPred[v]:
      kp = keyNum[p]
      parents[kv].add(kp)
      parents[kv] |= parents[kp]

  return (nk, parents)

def countPaths(nk, parents):
  # counting paths to cover DAG
  # analogous to bipartite matching (imagine splitting each vertex into input & output)
  nxt = [None] * nk
  def tryAug(v, visited=None):
    if visited is None: visited = set()

    visited.add(v)
    for nv in parents[v]:
      if nxt[nv] not in visited:
        # augmenting path when either nv is unmatched
        # or we reach an unmatched vertex from its match
        if (nxt[nv] is None) or tryAug(nxt[nv], visited):
          nxt[nv] = v
          return True
    return False

  # count one path for each (source-side) node that cannot be added to the matching
  return sum(not tryAug(v) for v in xrange(nk))

if __name__ == "__main__": sys.exit(main())
