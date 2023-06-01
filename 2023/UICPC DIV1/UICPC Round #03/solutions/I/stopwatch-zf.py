#!/usr/bin/python3

n = int(input())
t = [int(input()) for _ in range(n)]

if n&1: print("still running")
else: print(sum(t[i+1] - t[i] for i in range(0, n, 2)))
