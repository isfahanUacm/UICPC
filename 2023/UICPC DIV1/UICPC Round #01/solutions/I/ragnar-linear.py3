#!/bin/env python3
n = int(input())
l = []
for i in range(n):
    l.append(int(input()))
s = sum(l)
p = 0
ans = 0
for x in l:
    p += x*x
    s -= x
    ans = max(ans, p*s)
print(ans)
