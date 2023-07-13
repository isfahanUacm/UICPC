#!/bin/python3

n = int(input())

ans = 0
for _ in range(n):
    [f,y] = [float(x) for x in input().split()]
    ans += f*y

print(ans)
