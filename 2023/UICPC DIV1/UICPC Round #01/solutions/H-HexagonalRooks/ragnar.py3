#!/usr/bin/env python3
import sys

def canmove(p1, p2):
    if p1 == p2: return False
    def pos(p):
        f, r = p[0], int(p[1:])
        if f > 'f': r += ord(f)-ord('f');
        return f, r
    f1,r1 = pos(p1)
    f2,r2 = pos(p2)
    return f1 == f2 or r1 == r2 or ord(f2)-ord(f1) == r2-r1

p1, p2 = input().split()
ans = 0
for fo in range(0, 11):
    f = chr(ord('a')+fo)
    for r in range(1, 1+min(6+fo, 16-fo)):
        p = f + str(r)
        if canmove(p1, p) and canmove(p, p2):
            ans += 1

print(ans)
