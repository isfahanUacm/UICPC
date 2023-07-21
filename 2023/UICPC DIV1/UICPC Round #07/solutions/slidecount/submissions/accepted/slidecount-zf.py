#!/bin/python3

n, c = map(int, input().split())
w = [0]+list(map(int, input().split()))

s = e = id = 1
ps = w[1]
start, end = {1:id}, {}

while s <= n:
    id += 1
    if e+1 > n or ps + w[e+1] > c:
        end[s] = id
        ps -= w[s]
        s += 1
    else:
        e += 1
        start[e] = id
        ps += w[e]

print(*[end[i]-start[i] for i in range(1, n+1)], sep="\n")
