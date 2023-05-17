#!/usr/bin/env python3
n = int(input())

l = [int(input()) for _ in range(n)]

s = sum(l)

lps = [(0, s)]

for k in l: lps.append((lps[-1][0] + k**2, lps[-1][1] - k))

print(max(a * b for a, b in lps))
