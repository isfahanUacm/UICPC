#!/usr/bin/env python3
n = int(input())
ps=[]
for i in range(n): ps.append([int(x) for x in input().split()])
ps.sort()
M = 1+max(max(p) for p in ps)-min(min(p) for p in ps)
p = ps[n//2]
if n%2==1:
	ax, ay = (p[0]+1, p[1]-M)
	bx, by = (p[0]-1, p[1]+M)
else:
	ax, ay = (p[0]+1, p[1]-M-1)
	bx, by = (p[0]-1, p[1]+M)

print(ax+by-ay, ay+ax-bx)
print(ax-by+ay, ay-ax+bx)
