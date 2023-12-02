#!/usr/bin/env python3
t = int(input())
for tc in range(t):
    v = [int(a) for a in input().split()]
    v = [(v[2*i], v[2*i+1]) for i in range(3)]
    res = 10**20
    for s in range(3):
        a = v[s]
        b = v[0+(s==0)]
        c = v[1+(s<=1)]
        for ra in range(2):
            for rb in range(2):
                for rc in range(2):
                    w = b[rb] + c[rc]
                    h = max(b[not rb], c[not rc])
                    res = min(res, (a[ra]+w) * max(a[not ra], h))
                    res = min(res, max(a[ra], w) * (a[not ra] + h))
    print(res)
