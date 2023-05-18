#!/usr/bin/env python3
import math
n, k = [int(x) for x in input().split()]
ev = 0
for i in range(1, k+1):
    f = math.floor(ev)
    ev = ( f*ev + (n-f)*(n+f+1)/2 )/n
print(ev)
