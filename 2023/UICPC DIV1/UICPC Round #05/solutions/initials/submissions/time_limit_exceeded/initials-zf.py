#!/usr/bin/python3 

import sys

def gen(i, k):
    if k+1 <= names[i][1]:
        return names[i][0][:k+1] + names[i][0][names[i][1]]
    else:
        return names[i][0][:k+2]

def solve(i, k):
    global memo
    if (i, k) not in memo:
        if i == 0:
            memo[(i, k)] = k
        else:
            s = gen(i, k)
            memo[(i, k)] = 1000000
            for kk in range(len(names[i-1][0])-1):
                if gen(i-1, kk) < s:
                    memo[(i, k)] = min(memo[(i, k)], solve(i-1, kk) + k)
    return memo[(i, k)]

sys.setrecursionlimit(5000)

names = []

for i in range(int(input())):
    first, last = input().split()
    names.append((last.lower() + first.lower(), len(last)))

names.sort()
memo = {}

print(min(solve(len(names)-1, k) for k in range(len(names[-1][0])-1)))
