#!/usr/bin/env python3
# Use the minimal possible M for even and odd cases. Decreasing either by 1
# breaks the solution.
n = int(input())
ps=[]
for i in range(n): ps.append([int(x) for x in input().split()])
ps.sort()
M = max(max(p) for p in ps)-min(min(p) for p in ps)+1
p = ps[n//2]
if n%2==1:
    print(p[0]-M, p[1]-1)
    print(p[0]+M, p[1]+1)
else:
    print(p[0]-M//2, p[1]-1)
    print(p[0]+M//2, p[1]+0)
