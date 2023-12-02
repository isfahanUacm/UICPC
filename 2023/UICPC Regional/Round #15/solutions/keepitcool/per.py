(n, m, s, d) = map(int, raw_input().split())
c = map(int, raw_input().split())
r = [0]*s

for i in sorted(range(s), key = lambda i: c[i]):
    r[i] = min(n, d-c[i])
    n -= r[i]

if sum(c[i] for i in range(s) if not r[i]) >= m: print ' '.join(map(str, r))
else: print 'impossible'
