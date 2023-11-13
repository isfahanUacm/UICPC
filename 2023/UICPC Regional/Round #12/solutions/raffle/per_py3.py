#!/usr/bin/env python3
import sys

(n,p) = map(int, sys.stdin.read().split())

best = prod = 1.0*p/(n+1)
np = float(n-p)
for m in range(2, n+10):
    prod *= (np+m)/(n+m)
    val = prod*m
    if val > best:
        best = val
    else:
        break

print('%.6lf' % best)
