#!/bin/python3

import math

a, b = map(int, input().split())

def sqfree(x):
    y = 2
    while y*y <= x:
        if x % (y*y) == 0:
            return False
        y += 1
    return True

def isp(x):
    y = 2
    while y*y <= x:
        if x%y == 0:
            return False
        y += 1
    return True

if isp(a) and isp(b) and a != b:
    print("full credit")
elif sqfree(a) and sqfree(b) and math.gcd(a,b) == 1:
    print("partial credit")
else:
    print("no credit")
