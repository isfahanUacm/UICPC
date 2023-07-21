#!/bin/python3

# uses big decimals to get exact solution within precision

import sys, decimal

sys.setrecursionlimit(100050)

n, m = map(int, input().split())

uf = {v:v for v in range(1, n+1)}

def find(v):
    if uf[v] != v: uf[v] = find(uf[v])
    return uf[v]

for _ in range(m):
    u, v = map(int, input().split())
    uf[find(u)] = find(v)

sz = {v:0 for v in uf}
for v in uf: sz[find(v)] += 1

good = sum(sz[v]*(sz[v]-1)//2 for v in uf if uf[v] == v)

decimal.getcontext().prec = 20
ans_f = decimal.Decimal(good) / (n*(n-1)//2)
print(ans_f)
