#!/usr/bin/env python3
# brute force
import sys

a,b = map(int, sys.stdin.read().split())
for i in range(0, 180):
    if (a + i) % 360 == b:
        print(i)
        exit(0)
    if (a - i) % 360 == b:
        print(-i)
        exit(0)

print(180)
