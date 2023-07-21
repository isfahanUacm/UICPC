#!/bin/python3

import collections

a, b = map(int, input().split())

f = collections.defaultdict(int)

d = 2
while d*d <= max(a, b):
    while a%d == 0: a, f[d] = a//d, f[d]+1
    while b%d == 0: b, f[d] = b//d, f[d]+1
    d += 1
if a > 1: f[a] += 1
if b > 1: f[b] += 1

if set(f.values()) != {1}: print("no credit")
elif len(f) != 2: print("partial credit")
else: print("full credit")
