#!/usr/bin/env python3
n = int(input())
l = sorted([int(input()) for _ in range(1<<n)])
cur, got = [0], []
for _ in range(n):
    v = -1
    for i in range(len(cur)):
        if cur[i] != l[i]:
            v = l[i]
            break
    if v == -1: v = l[len(cur)]
    got.append(v)
    for i in range(len(cur)): cur.append(cur[i] + v)
    cur.sort()

if cur == l: [print(x) for x in got]
else: print("impossible")
