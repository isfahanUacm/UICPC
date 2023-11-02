#!/usr/bin/python3

binom = [[1 for i in range(51)] for i in range(51)]
for i in range(1,50):
    for j in range(1,i):
        binom[i][j] = binom[i-1][j] + binom[i-1][j-1]

n = int(input())

for cno in range(n):
    n, v1, v2, w = map(int, input().split())

    val = 0
    undec = n - v1 - v2
    for i in range(undec+1):
        vv1 = v1 + i
        vv2 = v2 + undec-i
        if vv1 > vv2: val += binom[undec][i]
    if 100*val > w*(2**undec):
        print("GET A CRATE OF CHAMPAGNE FROM THE BASEMENT!")
    elif val == 0:
        print("RECOUNT!")
    else:
        print("PATIENCE, EVERYONE!")
