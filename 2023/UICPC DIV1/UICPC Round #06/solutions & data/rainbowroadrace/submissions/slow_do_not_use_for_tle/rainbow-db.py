#!/bin/python3

from heapq import *

[n, m] = [int(x) for x in input().split()]

adj = [ [] for _ in range(n << 7) ]
dist = [ -1 for _ in range(n << 7) ]

for _ in range(m):
    line = input().split()
    u = int(line[0])-1
    v = int(line[1])-1
    d = int(line[2])
    c = "ROYGBIV".find(line[3])

    for j in range(1 << 7):
        adj[(u << 7) + j].append( [d, (v << 7) + (j | (1 << c))] )
        adj[(v << 7) + j].append( [d, (u << 7) + (j | (1 << c))] )

pq = []
heappush(pq, (0,0))
dist[0] = 0

end = (1 << 7)-1

while pq:
    d, v = heappop(pq)
    if dist[v] < d:
        continue
    if v == end:
        break
    for [w,u] in adj[v]:
        if dist[u] == -1 or dist[u] > dist[v] + w:
            dist[u] = dist[v] + w
            heappush(pq, (dist[u], u))

print(dist[end])
