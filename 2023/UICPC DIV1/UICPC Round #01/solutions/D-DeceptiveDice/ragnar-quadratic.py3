#!/usr/bin/env python3
n, k = [int(x) for x in input().split()]
ev = (n+1)/2.
for i in range(2, k+1):
    new_ev = 0
    for v in range(1, n+1):
        new_ev += max(v, ev)
    new_ev /= n
    ev = new_ev
print(ev)
