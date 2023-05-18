#!/usr/bin/env python3
# CANONICAL solution
from decimal import *
getcontext().prec=100

n, k = [int(x) for x in input().split()]
ev = (Decimal(n)+1)/2
for i in range(2, k+1):
    new_ev = 0
    for v in range(1, n+1):
        new_ev += max(v, ev)
    new_ev /= n
    ev = new_ev
print(f'{ev:.15f}')
