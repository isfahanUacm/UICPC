#!/usr/bin/env python2
import sys

data = map(int, sys.stdin.read().split())

(n, m, q) = data[:3]

ans = [0]*q
color = [[0]*m for _ in range(n)]
undo = [[] for _ in range(q)]
black = 0

nextx = [range(1, n+1) for _ in range(m)]
prevx = [range(-1, n-1) for _ in range(m)]
nexty = [range(1, m+1) for _ in range(n)]
prevy = [range(-1, m-1) for _ in range(n)]

par = range(n*m)
sz = [1]*(n*m)
components = n*m

def get_head(u):
    if par[u] != u: par[u] = get_head(par[u])
    return par[u]

def join(u, v):
    u = get_head(u)
    v = get_head(v)
    if u == v: return False
    if sz[u] < sz[v]:
        par[u] = v
    else:
        par[v] = u
        sz[u] += (sz[u] == sz[v])
    return True

for i in range(q):
    (x1, y1, x2, y2) = data[3+4*i:3+4*i+4]
    for x in range(x1-1, x2):
        for y in range(y1-1, y2):
            if color[x][y] == 0:
                undo[i].append((x, y))
                color[x][y] = 1
    black += len(undo[i])
                
for x in range(n):
    for y in range(m):
        if x > 0 and color[x-1][y] == 0 and color[x][y] == 0:
            components -= join(m*(x-1)+y, m*x+y)
        if y > 0 and color[x][y-1] == 0 and color[x][y] == 0:
            components -= join(m*x+y-1, m*x+y)

for i in range(q-1, -1, -1):
    ans[i] = components - black
    for (x, y) in undo[i]:
        color[x][y] = 0
        for (nx, ny) in [(x-1, y), (x+1, y), (x, y-1), (x, y+1)]:
            if 0 <= nx < n and 0 <= ny < m and color[nx][ny] == 0:
                components -= join(m*x+y, m*nx+ny)
    black -= len(undo[i])

print '\n'.join(map(str, ans))
