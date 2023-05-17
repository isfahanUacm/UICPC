#!/usr/bin/env python3
n = int(input())
if n%2==1: print((n+1)//2, n//2)
elif n%4==2: print('impossible')
else: print(n//4+1,n//4-1)
