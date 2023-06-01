#!/usr/bin/python3
import heapq

n,m = map(int, input().split())

graph = {i:[] for i in range(1, n+1)}

for i in range(m):
    u, v = map(int, input().split())
    graph[u].append(v)
    graph[v].append(u)

a = [0]
for i in range(n): a.append(int(input()))

#R = int(input())
R = 1

army = a[R]
seen = [False]*(n+1)
seen[R] = True

nbrs = [(a[i], i) for i in graph[R]]
heapq.heapify(nbrs)

while nbrs:
    nxt = heapq.heappop(nbrs)
    if seen[nxt[1]]: continue
    if nxt[0] >= army: break

    seen[nxt[1]] = True
    army += a[nxt[1]]
    for w in graph[nxt[1]]:
        heapq.heappush(nbrs, (a[w], w))

#print(len([x for x in seen if x])-1)
print(army)
