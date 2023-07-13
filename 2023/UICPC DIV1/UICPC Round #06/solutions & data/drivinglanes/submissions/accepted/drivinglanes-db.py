#!/bin/python3

[n,m] = [int(x) for x in input().split()]
[k,r] = [int(x) for x in input().split()]

L = [ int(input()) for _ in range(n) ]

C = [ [0,0] ]
for _ in range(n-1):
    C.append([int(x) for x in input().split()])

inf = 1000000000000000

A = [ [inf for _ in range(m)] for x in range(2)]
A[0][0] = 0

d = 0
for i in range(n-1,-1,-1):
    A[1-d] = [inf for _ in range(m)]
    for lane in range(m):
        for change in range(m+1):
            if change * k > L[i]:
                break
            if lane+change < m:
                A[1-d][lane+change] = min(A[1-d][lane+change], A[d][lane] + L[i] + change * r + C[i][0] + C[i][1] * (lane+change+1))
            if lane-change >= 0:
                A[1-d][lane-change] = min(A[1-d][lane-change], A[d][lane] + L[i] + change * r + C[i][0] + C[i][1] * (lane-change+1))
    d = 1-d

print(A[d][0])
