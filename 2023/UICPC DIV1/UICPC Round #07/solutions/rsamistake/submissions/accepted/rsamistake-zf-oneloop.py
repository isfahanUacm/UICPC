#!/bin/python3

def solve(a, b):
    na, nb = 0, 0
    d = 2
    while d*d <= max(a, b):
        if a%(d**2) == 0 or b%(d**2) == 0 or (a%d == 0 and b%d == 0): return "no credit"
        if a%d == 0: a, na = a//d, na+1
        if b%d == 0: b, nb = b//d, nb+1
        d += 1

    if a > 1 and a == b: return "no credit"
    if a > 1: na += 1
    if b > 1: nb += 1

    return "full credit" if na == 1 and nb == 1 else "partial credit"

print(solve(*map(int, input().split())))
