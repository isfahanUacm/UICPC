#!/usr/bin/env python3
M, n, v = 1000000000+7, int(input()), [(0,1)]
def op(a, b): return ((a[0] + b[1])%M, a[1] * b[0]%M)
for s in input().split():
    if s == '(': v.append((0,1))
    else:
        x = v.pop() if s == ')' else (int(s), int(s))
        v[-1] = op(v[-1], x)
print(v[0][0])
