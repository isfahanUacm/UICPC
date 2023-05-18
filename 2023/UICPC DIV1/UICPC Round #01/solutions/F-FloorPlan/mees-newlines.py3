#!/usr/bin/env python2
n = int(input())

if n % 4 == 0:
    print(n//4 + 1)
    print(n//4 - 1)
elif n % 2 == 0:
    print("impossible")
else:
    print((n+1)//2)
    print((n-1)//2)
