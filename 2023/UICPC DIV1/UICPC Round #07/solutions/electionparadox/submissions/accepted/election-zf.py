#!/bin/python3

n = int(input())
p = sorted(map(int, input().split()))[::-1]

win = sum(p[:n//2]) + sum(x//2 for x in p[n//2:])
print(win)
