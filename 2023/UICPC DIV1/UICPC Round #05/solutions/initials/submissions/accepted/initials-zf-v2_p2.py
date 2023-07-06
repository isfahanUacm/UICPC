#!/usr/bin/python2

import sys

def gen(i, k):
    if k+1 <= names[i][1]:
        return names[i][0][:k+1] + names[i][0][names[i][1]]
    else:
        return names[i][0][:k+2]

sys.setrecursionlimit(5000)

names = []

for i in range(int(input())):
    first, last = raw_input().split()
    names.append((last.lower() + first.lower(), len(last)))

names.sort()
memo = {}

for i in range(len(names)):
    for k in range(len(names[i][0])-1):
        if i == 0:
            memo[(i,k)] = k
        else:
            s = gen(i, k)
            best = 1000000
            for kk in range(len(names[i-1][0])-1):
                if gen(i-1, kk) < s:
                    best = min(best, memo[(i-1, kk)]+k)
            memo[(i, k)] = best

print(min(memo[(len(names)-1, k)] for k in range(len(names[-1][0])-1)))
