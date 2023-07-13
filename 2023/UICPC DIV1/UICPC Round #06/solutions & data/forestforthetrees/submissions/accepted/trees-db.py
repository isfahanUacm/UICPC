#!/bin/python3

from fractions import gcd

[x,y] = [int(x) for x in input().split()]
[x1,y1,x2,y2] = [int(x) for x in input().split()]

g = gcd(x,y)

X, Y = x//g, y//g

if x1 <= X and X <= x2 and y1 <= Y and Y <= y2:
    k = min(x2//X, y2//Y) + 1
    X *= k
    Y *= k

if x <= X:
    print("Yes")
else:
    print("No")
    print(X,Y)
