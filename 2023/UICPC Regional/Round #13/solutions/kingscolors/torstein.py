#!/usr/bin/env python2
from sys import stdin
MOD = int(1e9+7)
    
def landoftrees():
    # Problem: Land of Trees
    # Author: Torstein Stromme
    
    # The problem: Given a tree, how many ways to color
    # the tree with exactly k colors?
    
    # Solution strategy:
    #
    # We build a DP table t[n][k] = the number of ways to
    # color a tree on n vertices with exactly k colors.
    # The base cases:
    #  - When n == k, there are n! ways to color the graph
    #  - When k == 2, then there are two ways to color the graph
    # Recursive case:
    # Consider some leaf vertex. Either it is the only vertex of
    # some color, or it has the same color as someone else. In
    # the former case, there are k * t[n-1][k-1] options, in the
    # latter case there are (k-1) * t[n-1][k] options.
    #
    # Notice that the structure of the tree is actually irrelevant.
    # We migth as well assume the tree is a path on n vertices and
    # ignore the rest of the input.
    
    N, K = map(int, stdin.readline().split())
    t = [[0] * (N+1) for i in range(K+1)]

    # Base case
    for i in range(2,N+1): t[2][i] = 2
    t[1][1] = 1
    for i in range(2,K+1): t[i][i] = (t[i-1][i-1] * i) % MOD
    
    # Recursive case
    for k in range(3, K+1):
        for n in range(k+1, N+1):
            t[k][n] = (k * t[k-1][n-1] + (k-1) * t[k][n-1]) % MOD
            
    return t[K][N]
            
print(landoftrees())
