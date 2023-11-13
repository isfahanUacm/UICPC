# This solution works also for n-dimensional walks...
import sys
import math

def read_walk():
    return [map(float, sys.stdin.readline().split()) for _ in range(int(sys.stdin.readline()))]+[None]

def dot(P, Q): return sum(map(lambda (p, q): p*q, zip(P, Q)))
def sub(P, Q): return map(lambda (p, q): p-q, zip(P, Q))
def dist(P): return math.sqrt(dot(P, P))

A = iter(read_walk())
B = iter(read_walk())

a1 = next(A)
a2 = next(A)
b1 = next(B)
b2 = next(B)
ans = 1e30

while a2 is not None and b2 is not None:
    ad = dist(sub(a2, a1))
    bd = dist(sub(b2, b1))
    if ad > bd:
        (A, a1, a2, ad, B, b1, b2, bd) = (B, b1, b2, bd, A, a1, a2, ad)

    nb = map(lambda (x, y): x + (y-x)*ad/bd, zip(b1, b2))
    
    lo = 0.0
    hi = 1.0

    v0 = sub(a1, b1)
    v1 = sub(sub(a2, a1), sub(nb, b1))
        
    c0 = dot(v0, v0)
    c1 = dot(v0, v1)
    c2 = dot(v1, v1)
    
    for _ in range(100):
        t1 = (2*lo+hi)/3
        t2 = (lo+2*hi)/3

        d1 = c0 + 2*c1*t1 + c2*t1*t1
        d2 = c0 + 2*c1*t2 + c2*t2*t2

        if d1 > d2:
            lo = t1
        else:
            hi = t2

    ans = min(ans, d1)

    b1 = nb
    a1 = a2
    a2 = next(A)

print math.sqrt(ans)
