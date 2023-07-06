#!/usr/bin/python3

from collections import deque

INFTY = 10000000000000

edges = []
graph = dict()

def addEdge(u, v, c):
    if u not in graph: graph[u] = set()
    graph[u].add(len(edges))
    edges.append((u, v, c))

    if v not in graph: graph[v] = set()
    graph[v].add(len(edges))
    edges.append((v, u, 0))


def augment(s, t):
    global edges

    path = {s: -1}
    q = deque([s])

    while q:
        cur = q.popleft()
        for i in graph[cur]:
            nxt = edges[i][1]
            if edges[i][2] > 0 and nxt not in path:
                path[nxt] = i
                q.append(nxt)

    if t not in path: return 0

    aug = INFTY
    tt = t
    while tt != s:
        i = path[tt]
        tt = edges[i][0]
        aug = min(aug, edges[i][2])

    tt = t
    while tt != s:
        i = path[tt]
        tt = edges[i][0]
        edges[i] = (edges[i][0], edges[i][1], edges[i][2]-aug)
        edges[i^1] = (edges[i^1][0], edges[i^1][1], edges[i^1][2]+aug)

    return aug

def maxFlow(s, t):
    flow = 0
    while True:
        aug = augment(s, t)
        if aug == 0: return flow
        flow += aug

n = int(input())
totVal = 0
for i in range(1, n+1):
    line = list(map(int, input().split()))
    totVal += line[0]
    addEdge(0, i, line[0])
    addEdge(i, n+1, line[1])
    for obs in line[3:]:
        addEdge(obs, i, INFTY)

print(totVal-maxFlow(0, n+1))
