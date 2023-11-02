#!/usr/bin/python3

import heapq

def dfs(bip, ml, mr, u, seen):
    if seen[u]: return False
    seen[u] = True
    for v in bip[u]:
        if mr[v] == -1 or dfs(bip, ml, mr, mr[v], seen):
            ml[u], mr[v] = v, u
            return True
    return False

def augment(bip, ml, mr):
    seen = {u:False for u in bip}
    for u in bip:
        if ml[u] == -1 and dfs(bip, ml, mr, u, seen):
            return True
    return False

def match(bip):
    ml = {u:-1 for u in bip}
    mr = {u:-1 for u in bip}

    cnt = 0
    while (augment(bip, ml, mr)): cnt += 1
    return cnt

def dijkstra(s, g):
    inf = 10**15
    dist = [inf for i in range(n)]
    heap = [(0,s)]

    while heap:
        d, curr = heapq.heappop(heap)
        if dist[curr] != inf: continue
        dist[curr] = d
        for nxt, w in g[curr]:
            heapq.heappush(heap, (d+w, nxt))

    return dist

n, m, c = map(int, input().split())

cl = set(map(int, input().split()))

g = {i:[] for i in range(n)}

for i in range(m):
    u,v,w = map(int, input().split())
    g[u].append((v,w))

d = {}

d[0] = dijkstra(0, g)
for x in cl:
    d[x] = dijkstra(x, g)

bip = {x:[] for x in cl}
for x in cl:
    for y in cl:
        if d[0][y] == d[0][x] + d[x][y] and x != y:
            bip[x].append(y)

print(c - match(bip))
