#!/usr/bin/python3
import sys

def mult_poly(A, B):
    n = len(A)
    m = len(B)
    C = [0.0] * (n + m - 1)
    for i in range(n):
        for j in range(m):
            C[i + j] += A[i] * B[j]
    return C

n,k = [int(x) for x in input().split()]
A = [float(x) for x in input().split()]

best = 0
P = [1.0]
for a in sorted(A, reverse=True):
    P = mult_poly([1-a, a], P)

    m = len(P) - 1 # Problems attempted
    tmp = 0.0
    for i in range(m + 1):
        s = 2 * i - m # #AC - #WA
        if s >= k:
            tmp += P[i]
    best = max(best, tmp)

print(best)
