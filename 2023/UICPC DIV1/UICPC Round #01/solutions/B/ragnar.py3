#!/usr/bin/env python3
M, n, v = 1000000000+7, int(input()), [0]
for s in input().split():
    if s == '(': v.append(0 if len(v)%2==0 else 1)
    else:
        x = v.pop() if s == ')' else int(s)
        v[-1] = (v[-1] + x if len(v)%2==1 else v[-1]*x)%M
print(v[0])
