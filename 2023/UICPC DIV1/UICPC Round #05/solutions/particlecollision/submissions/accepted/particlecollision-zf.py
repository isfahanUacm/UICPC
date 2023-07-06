#!/usr/bin/python3

import math

def dot(a, b):
    return a[0]*b[0] + a[1]*b[1]

# returns t such that b - (a + t*vec) is the time of collision, -1 if no collision
def collide(a, b, vec, rad):
    bb = [b[i]-a[i] for i in range(2)]
    A = dot(vec, vec)
    B = -2*dot(vec, bb)
    C = dot(bb, bb) - (2*rad)**2

    if A < 0: return -1
    disc = B*B - 4*A*C
    if disc < 0: return -1
    t = (-B - math.sqrt(disc))/(2*A)
    if t < 0: return -1

    return t

w = list(map(float, input().split()))
r = list(map(float, input().split()))
b = list(map(float, input().split()))
d = list(map(float, input().split()))
rad= d[2]
d = d[:2]

adj = 0

t1, t2 = collide(w, r, d, rad), collide(w, b, d, rad)
if t2 != -1 and (t1 == -1 or t2 < t1):
    r, b = b, r
    adj += 1
    t1, t2 = t2, t1

nd = [r[i] - (w[i] + d[i]*t1) for i in range(2)]
if t1 == -1: print(5)
elif collide(r, b, nd, rad) == -1: print(3+adj)
else: print(1+adj)
