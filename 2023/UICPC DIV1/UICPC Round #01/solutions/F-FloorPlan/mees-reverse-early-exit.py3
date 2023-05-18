#!/usr/bin/env python3
# We want n = m^2 - k^2 = (m - k)(m + k)
# So iterate over (m-k), guess at m + k, output impossible if you find nothing.

import sys

n = int(input())

if n == 0:
    print(2, 2)
    sys.exit()

for s in range(1, 10000):
    if n % s != 0:
        continue
    b = n // s

    k = (b - s) // 2
    m = (b + s) // 2
    if n == m**2 - k**2:
        print(m, k)
        sys.exit()

print("impossible")
