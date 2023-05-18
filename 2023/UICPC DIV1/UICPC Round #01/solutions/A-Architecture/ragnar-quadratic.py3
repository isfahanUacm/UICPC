#!/usr/bin/env python3

r, c = [int(x) for x in input().split()]
rm = [int(x) for x in input().split()]
cm = [int(x) for x in input().split()]

grid = [[min(rm[i], cm[j]) for j in range(c)] for i in range(r)]

ok = True
for i in range(r):
    if rm[i] != max(grid[i]):
        ok = False
for j in range(c):
    if cm[j] != max(grid[i][j] for i in range(r)):
        ok = False
print('possible' if ok else 'impossible')
