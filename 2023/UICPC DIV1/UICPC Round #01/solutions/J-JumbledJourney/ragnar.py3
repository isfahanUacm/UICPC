#!/usr/bin/env python3
n = int(input())
avg = [[int(x) for x in input().split()] for _ in range(n)]
count = [[0 for _ in range(n)] for _ in range(n)]
dist = [[-1 for _ in range(n)] for _ in range(n)]
done = [False] * n

ts = []
def visit(u):
    if done[u]: return
    done[u] = True
    [visit(v) for v in range(n) if avg[v][u] > 0]
    ts.append(u)
for i in range(n): visit(i)
    
for j in range(n):
    for i in reversed(range(j)):
        u, v, cur_sum = ts[i], ts[j], 0
        if avg[u][v] == -1: continue
        for w in ts[i+1:j]:
            if dist[u][w] > 0:
                count[u][v] += count[w][v]
                cur_sum += count[w][v] * (avg[w][v] + dist[u][w])
        d = avg[u][v] * (count[u][v] + 1) - cur_sum
        # 0 < d <= avg[u][v] by triangle inequality. Only add if strictly smaller.
        if d < avg[u][v] or count[u][v] == 0:
            dist[u][v] = d
            count[u][v] += 1

for d in dist: print(*d)