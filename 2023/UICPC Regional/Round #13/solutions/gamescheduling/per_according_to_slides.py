def round_robin(n):
    g = n-1 + n%2
    S = [[] for _ in range(n)]
    for x in range(g):
        for i in range(g):
            j = (x-i) % g
            if j == i and n%2 == 0: j = g
            if j >= i: S[x].append((i,j))
    return S

(n, m) = map(int, raw_input().split())
S = []
psched = round_robin(n)
tsched = round_robin(m)
for pday in psched:
    if not pday: break
    for s in range(1,m):
        day = []
        for (i, j) in pday:
            if i == j:
                day.extend([(u*n+i, v*n+i) for (u, v) in tsched[s-1] if u != v])
            elif s > 0:
                day.extend([(t*n+i, (t+s)%m*n+j) for t in range(m)])
        S.append(day)
if n % 2 == 0:
    for rday in tsched:
        S.append([(u*n+i, v*n+i) for i in range(n) for (u, v) in rday if u != v])
elif m % 2 != 0:
    S.append([(u*n+i, v*n+i) for i in range(n) for (u, v) in tsched[m-1] if u != v])
        
def format(t):
    return '%s%d' % (chr(65 + t / n), 1 + t % n)

for day in S:
    print ' '.join(['%s-%s' % (format(t1), format(t2)) for t1, t2 in day])
