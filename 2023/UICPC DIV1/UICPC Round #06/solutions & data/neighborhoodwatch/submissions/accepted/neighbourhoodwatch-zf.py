#!/usr/bin/python3

n, k = map(int, input().split())
loc = [int(input()) for _ in range(k)]+[0,n+1]
loc.sort()

def f2(x): return max(x*(x-1)//2+x, 0)

tot = f2(n)
for i in range(k+1):
    tot -= f2(loc[i+1]-loc[i]-1)

print(tot)
