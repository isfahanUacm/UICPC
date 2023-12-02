n=int(raw_input())
P=map(int,raw_input().split())
F=map(int,raw_input().split())
lo=[0]*n
hi=[float("inf")]*n
adj=[[] for _ in range(n)]
for i in range(n-1):
    adj[P[i]-1] += [i+1]

try:
    stack = [(0, True)]
    while stack:
        u, fst = stack[-1]
        del stack[-1]
        if fst:
            stack += [(u, False)]
            stack += [(v, True) for v in adj[u]]
        else:
            w = sum(hi[v] == float("inf") for v in adj[u])
            if adj[u] and w == 0:
                hi[u] = sum(hi[v] for v in adj[u])
            if w > 1:
                for v in adj[u]:
                    hi[v] = lo[v]
            lo[u] = max(1, sum(lo[v] for v in adj[u]))
            if F[u] != 0:
                lo[u] = hi[u] = F[u]
            assert lo[u] <= hi[u]
    assert lo[0] > 0 and hi[0] < float("inf")
    stack = [0]
    while stack:
        u = stack[-1]
        del stack[-1]
        rem = lo[u]
        w = 0
        for v in adj[u]:
            stack += [v]
            rem -= lo[v]
            if lo[v] < hi[v]:
                w = v
        assert w or (rem == 0 and adj[u]) or (rem > 0 and not adj[u])
        if w: lo[w] = lo[w] + rem
    for g in lo:
        print g
except Exception as e:
    print 'impossible'
