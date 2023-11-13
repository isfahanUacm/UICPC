#! /usr/bin/env python3
import sys
data = list(map(int, sys.stdin.read().split()[1:]))

val = []
idx = {}
for d in data:
    if d not in idx:
        val.append(d)
        idx[d] = len(idx)

V = len(idx)
adj = [[] for _ in range(V)]

for (s, t) in zip(data[::2], data[1::2]):
    (si, ti) = (idx[s], idx[t])
    adj[si].append(ti)
    adj[ti].append(si)

tot = 0
Q = [0] * V
seen = [False]*V

for u in range(V):
    if not seen[u]:
        seen[u] = True
        qs = 1
        Q[0] = u
        bal = 0
        ctot = 0
        maxv = 0
        while qs > 0:
            qs -= 1
            v = Q[qs]
            bal += len(adj[v])-2
            ctot += val[v]*(len(adj[v])-1)
            maxv = max(maxv, val[v])
            for w in adj[v]:
                if not seen[w]:
                    seen[w] = True
                    Q[qs] = w
                    qs += 1

        tot += ctot + (maxv if bal < 0 else 0)

print(tot)
