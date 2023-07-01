#!/usr/bin/env python
# -*- coding: utf-8
#Solution by lukasP (Luká¿ Polá¿ek)
from sys import stdin
import math


def factor(x):
    for i in range(2, int(1 + math.sqrt(x))):
        if x % i == 0:
            po = 1
            while x % i == 0:
                po *= i
                x //= i
            yield (i, po)
    if x > 1:
        yield (x, x)


def inverse(x, mod):
    if mod == 1:
        return 1
    return [y for y in range(1, mod) if y * x % mod == 1][0]


def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)


s = stdin.readline().split()
n, k = int(s[0]), int(s[1])
a = map(lambda x: int(x) - 1, stdin.readline().split())

cycles = [[] for x in range(n)]
seen = [False] * n
for i in [x for x in range(n)]:
    if not seen[i]:
        cyc = []
        u = i
        while True:
            cyc.append(u)
            seen[u] = True
            u = a[u]
            if u == i:
                break
        cycles[len(cyc)].append(cyc)

po = dict(factor(k))
res = [-1] * n

for group in filter(lambda x: len(x) > 0, cycles):
    ln = len(group[0])
    need = reduce(lambda x, y: x * y, [po[x[0]] for x in factor(ln) if x[0] in po], 1)

    if len(group) % need == 0:
        for i in range(0, len(group), need):
            cyc = []
            for l in range(ln):
                for j in range(need):
                    cyc.append(group[i + j][l])

            move = inverse(k // need % ln, ln)
            for j in range(len(cyc)):
                res[cyc[j]] = cyc[(j + move) % len(cyc)]

if any(x for x in res if x == -1):
    print "Impossible"
else:
    print " ".join(str(x + 1) for x in res)
