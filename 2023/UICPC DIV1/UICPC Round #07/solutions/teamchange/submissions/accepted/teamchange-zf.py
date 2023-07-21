#!/bin/python3

import sys

sys.setrecursionlimit(100000)

def add_edge(u, v, c):
    if v not in g[u]: g[u][v] = 0
    if u not in g[v]: g[v][u] = 0
    g[u][v] += c

def augment(v, pre, t, mn, par):
    if v == t: return mn
    if v in par: return 0
    par[v] = pre

    for w in g[v]:
        if g[v][w]:
            nxt = augment(w, v, t, min(mn, g[v][w]), par)
            if nxt:
                g[v][w] -= nxt
                g[w][v] += nxt
                return nxt
    return 0


N, R = map(int, input().split())
team = input()
change = input()

def In(v): return 2*v
def Out(v): return 2*v+1

g = {v : {} for v in range(2*N+2)}
s, t = 2*N, 2*N+1

for i in range(N):
    if change[i] != "?":
        if team[i] == change[i]: add_edge(s, In(i), 2)
        else: add_edge(Out(i), t, 2)
    add_edge(In(i), Out(i), 1)

for _ in range(R):
    u, v = map(int, input().split())
    u -= 1
    v -= 1
    add_edge(Out(u), In(v), 2)
    add_edge(Out(v), In(u), 2)

par = {}
while augment(s, -2, t, 10**9, par): par = {}

ans = {}
for i in range(N):
    if Out(i) in par: ans[i] = team[i]
    elif In(i) in par: ans[i] = 'X'
    else: ans[i] = {"A":"B", "B":"A"}[team[i]]
print("".join(ans[i] for i in range(N)))
