import heapq

(n, m) = map(int, raw_input().split())
G = [[] for _ in range(n+1)]
for _ in range(m):
    (u, v, d) = map(int, raw_input().split())
    G[u].append((v, d))
    G[v].append((u, d))

D = [[]]
for u in range(1, n+1):
    dst = [1<<60]*(n+1)
    D.append(dst)
    dst[u] = 0
    Q = [(0, u)]
    while Q:
        (d, u) = heapq.heappop(Q)
        if d > dst[u]: continue
        for (v, add) in G[u]:
            if d+add < dst[v]:
                dst[v] = d+add
                heapq.heappush(Q, (dst[v], v))

k = int(raw_input())
orders = [map(int, raw_input().split()) for _ in range(k)]

def ok(delay):
    max_start = [-1]*(k+1)
    max_start[k] = 1<<60
    for i in range(k-1, -1, -1):
        at = 1
        here = 1<<60
        tot_dist = 0
        for j in range(i, k):
            tot_dist += D[at][orders[j][1]]
            at = orders[j][1]
            here = min(here, orders[j][0] + delay - tot_dist)
            if here < orders[j][2]: break
            there = max_start[j+1] - tot_dist - D[at][1]
            if there >= orders[j][2]:
                max_start[i] = max(max_start[i], min(here, there))
        if max_start[i] < 0: return False
    return True

lo = -1
hi = 1<<50
while hi-lo > 1:
    mid = (lo+hi)/2
    if ok(mid): hi = mid
    else: lo = mid
print hi
