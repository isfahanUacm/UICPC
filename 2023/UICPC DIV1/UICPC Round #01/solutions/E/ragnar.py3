#!/bin/env python3
n, m = [int(x) for x in input().split()]
inc, dec = [], []
for i in range(1, m+1):
    u, v = [int(x) for x in input().split()]
    if u > v: inc.append(i)
    else: dec.append(i)
if len(inc) > len(dec): inc = dec
print(len(inc))
print(*inc)
