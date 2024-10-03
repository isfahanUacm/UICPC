#!/usr/bin/env python3
import sys
V, E = [int(x) for x in input().split()]

G = [[] for _ in range(V)]
eds = []
for _ in range(E):
    a, b = [int(x) - 1 for x in input().split()]
    G[a].append(b)
    G[b].append(a)
    eds.append((a, b))

def bfs(source):
    D = [V + 1] * V
    counts = [0] * V
    
    D[source] = 0
    q = [source]
    qi = 0
    mincyc = V + 1
    while qi < len(q):
        cur = q[qi]
        qi += 1
        if 2 * D[cur] + 1 > mincyc: continue
        for u in G[cur]:
            if D[u] > D[cur] + 1:
                D[u] = D[cur] + 1
                counts[u] += 1
                q.append(u)
            elif D[u] == D[cur] + 1:
                counts[u] += 1
                mincyc = min(mincyc, 2 * D[u])
            elif D[u] == D[cur]:
                mincyc = min(mincyc, 2 * D[cur] + 1)

    if mincyc == V + 1: return None, None
    if mincyc % 2 == 1:
        return mincyc, sum(1 for a, b in eds if D[a] == D[b] == mincyc // 2)
    return mincyc, sum(c * (c - 1) // 2 for i, c in enumerate(counts) if D[i] == mincyc // 2)

mincyc = V + 1
res = 0

for i in range(V):
    cyclen, cyccount = bfs(i)
    if not cyccount: continue
    if cyclen < mincyc:
        mincyc = cyclen
        res = 0
    if cyclen == mincyc:
        res += cyccount

print(mincyc, file=sys.stderr)
print(res // mincyc)
