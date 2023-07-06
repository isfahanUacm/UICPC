#!/usr/bin/python3

def f(x, at):
    if at == n: return 0, 2**l[x]

    cleft, vleft = f(x, at+1)
    cright, vright = f(x + (2**at), at+1)

    tot = cleft + cright
    if (vleft|vright) == 3: tot += 1
    return tot, (vleft|vright)

n = int(input())
l = list(map(int, input().split()))

cnt, val = f(0, 0)
print(2*cnt+1)
