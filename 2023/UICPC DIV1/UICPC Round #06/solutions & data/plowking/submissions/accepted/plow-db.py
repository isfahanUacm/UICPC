#!/bin/python3

import math

[n, m] = [int(x) for x in input().split()]

d = int((3 + math.sqrt(3*3 - 4*2*(n-m))) / 2);
if 1 - 3 + 2*(n-m) >= 0:
    d = 1

while d * (d-1) // 2 + (n-d) < m:
    d += 1

ans = (d*d*d - 3*d*d + 8*d - 6) // 6;
ans += m * (m+1) // 2 - (m-n+d) * (m-n+d+1) // 2

print(ans)
