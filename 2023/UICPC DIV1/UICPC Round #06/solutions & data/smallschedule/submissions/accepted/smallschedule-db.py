#!/bin/python3

[Q, M, S, L] = [int(x) for x in input().split()]

while L % M != 0 and S > 0:
    L += 1
    S -= Q

if S < 0:
    S = 0

print( Q * ((L+M-1) // M) + (S+M-1) // M )
