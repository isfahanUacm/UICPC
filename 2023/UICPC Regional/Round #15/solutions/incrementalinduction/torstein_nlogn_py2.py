#!/usr/bin/env python2
from sys import stdin

## Solution to Diploma Ceremony
## Author: Torstein Stromme

## Apart from reading the input, this algorithm runs in O(n log n)
## It also has O(n) space usage (doesn't store the entire graph).

## Read graph
n = int(stdin.readline())
outdeg = [0] * n
for i, line in enumerate(stdin.readlines()):
    for j in xrange(i+1):
        if line[j] == "1":
            outdeg[i+1] += 1
        else:
            outdeg[j] += 1
    
## Find optimal order
order = sorted(range(n), key=lambda i: -outdeg[i]) # negative sorts bwards

## Calculate k (worst across all cuts)
max_k = 0
b_out = n * (n - 1) // 2

for i, player in enumerate(order):
    b_out -= outdeg[player]
    max_k = max(max_k, b_out - (n-i-1) * (n-i-2) // 2)
    
## Print result
print(max_k)