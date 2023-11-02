#!/usr/bin/python3

n, m = map(int, input().split())

p = []
for i in range(n): p.append(list(map(int, input().split())))

d = []

for j in range(n):
    d.append([])
    for i in range(m):
        previ = 0
        if i > 0: previ = d[j][i-1]
        prevj = 0
        if j > 0: prevj = d[j-1][i]
        d[j].append(p[j][i] + max(previ, prevj))

print(*[d[j][m-1] for j in range(n)])
