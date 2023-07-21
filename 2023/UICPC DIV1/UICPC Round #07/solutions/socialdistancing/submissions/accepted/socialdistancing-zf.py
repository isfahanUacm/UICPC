#!/bin/python3

S, N = map(int, input().split())
A = list(map(int, input().split()))
A.append(A[0]+S)
print(sum((A[i+1] - A[i] - 2)//2 for i in range(N)))
