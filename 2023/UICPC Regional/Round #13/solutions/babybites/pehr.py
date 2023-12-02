#!/usr/bin/python2.7

from sys import stdin

def solve():
    n = int(stdin.readline())
    line = stdin.readline().split()
    for i in range(0,n):
        if (line[i] != 'mumble' and int(line[i])!=i+1):
            return "something is fishy"
    return 'makes sense'

print solve()
