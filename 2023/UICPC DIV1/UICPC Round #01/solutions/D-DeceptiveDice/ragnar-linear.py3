#!/usr/bin/env python3
from math import floor
n, k, ev = [int(x) for x in input().split()] + [0]
for i in range(1, k+1): ev = (floor(ev)*ev+(n-floor(ev))*(n+floor(ev)+1)/2)/n
print(ev)
