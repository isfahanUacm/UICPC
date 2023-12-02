#!/usr/bin/env python2
from sys import stdin

## Solution to Diploma Ceremony
## Author: Torstein Stromme

## Most straigthforward solution to Diploma Ceremony, runs in O(n^2)
## Space usage is also O(n^2), since the entire graph is stored

## Read graph
n = int(stdin.readline().strip())
graph = [[False]*n for _ in range(n)]
for i, line in enumerate(stdin.readlines()):
    for j in xrange(i+1):
        if line[j] == "1":
            graph[i+1][j] = True
        else:
            graph[j][i+1] = True
    
## Find optimal order
order = sorted(range(n), key=lambda i: -sum(graph[i])) # negative sorts bwards

## Calculate minimum k ("naively" by examining edges)
max_k = 0
run_k = 0
is_winner = [False] * n

for player in order:
    is_winner[player] = True
    for opponent in range(n):
        p_won = graph[player][opponent]
        if p_won and is_winner[opponent]:
            run_k -= 1
        elif not p_won and not is_winner[opponent]:
            run_k += 1
    max_k = max(max_k, run_k)
    
## Print result
print(max_k)