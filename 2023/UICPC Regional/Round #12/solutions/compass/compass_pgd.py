#!/usr/bin/env python3
# jmv's java solution in python
import sys

def rot(a,b):
    d = b-a
    if d > 180:
        d -= 360
    elif d <= -180:
        d += 360
    return d

a,b = map(int, sys.stdin.read().split())
print(rot(a,b))
