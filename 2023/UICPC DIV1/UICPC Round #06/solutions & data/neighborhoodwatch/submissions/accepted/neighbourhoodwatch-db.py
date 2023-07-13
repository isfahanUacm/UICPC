#!/bin/python3

[n,k] = [int(x) for x in input().split()]

ans = 0
last = 0
for _ in range(k):
    H = int(input())
    ans += (H-last) * (n-H+1)
    last = H

print(ans)
