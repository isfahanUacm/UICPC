(n, m) = map(int, raw_input().split())
(b, r) = map(int, raw_input().split())
totplay = [[0]*m for _ in range(n)]
firstplay = [[b+1]*m for _ in range(n)]
curtoy = [(-1, 0)]*n
curkid = [(-1, 0)]*m
for (s, k, t) in [map(int, raw_input().split()) for _ in range(r)]:
    k -= 1
    t -= 1
    if t != -1: firstplay[k][t] = min(firstplay[k][t], s)
    (pt, ps) = curtoy[k]
    if pt == t: continue
    if pt != -1:
        totplay[k][pt] += s - ps
        curkid[pt] = (-1, 0)
    if t != -1:
        (pk, ps) = curkid[t]
        if pk != -1:
            totplay[pk][t] += s - ps
            curtoy[pk] = (-1, 0)
        curkid[t] = (k, s)
    curtoy[k] = (t, s)
for i in range(n):
    if curtoy[i][0] != -1: totplay[i][curtoy[i][0]] += b - curtoy[i][1]

if m < n:
    print 'impossible'
else:
    wish = [iter(sorted(range(m), key = lambda t: firstplay[k][t])) for k in range(n)]
    kid = [-1]*m
    toy = [0]*n
    for k in range(n):
        while k >= 0:
            t = next(wish[k])
            if kid[t] < 0 or totplay[k][t] < totplay[kid[t]][t]:
                toy[k] = t+1
                (k, kid[t]) = (kid[t], k)
    print ' '.join(map(str, toy))
