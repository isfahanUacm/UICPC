#!/usr/bin/python3

# python is stupid, this approach with "static" arrays
# and bottom-up for loops is slower than using hash tables
# and a top-down recursive approach

cno = int(input())
memo = [[0 for i in range(200)] for i in range(200)]

for i in range(cno):
    s = input()
    n = len(s)
    for ln in range(0,n):
        for i in range(n-ln):
            j = i+ln
            if i == j: memo[i][j] = 1
            else:
                memo[i][j] = memo[i][j-1] + 1
                for k in range(i,j):
                    if s[k] != s[j]: continue
                    val = memo[i][k]
                    if k+1 <= j-1: val += memo[k+1][j-1]
                    memo[i][j] = min(memo[i][j], val)
    print(n+2*memo[0][n-1])
