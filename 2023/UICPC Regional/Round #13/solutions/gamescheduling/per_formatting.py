import random
random.seed(2018) # for determinism

def ham_cycle_cover(m):
    used = [[False]*m for _ in range(m)]
    for i in range(m): used[i][i] = True

    res = []
    while len(res) < (m-1)/2:
        for _ in range(100):
            C = [0]
            for _ in range(m-1):
                cands = [v for v in range(m) if not used[C[-1]][v] and v not in C]
                if not cands:
                    break
                C.append(random.choice(cands))
            if len(C) == m and not used[C[-1]][0]: break
        else:
            return []
        res.append(C)
        for i in range(m):
            assert not used[C[i-1]][C[i]]
            assert not used[C[i]][C[i-1]]
            used[C[i-1]][C[i]] = used[C[i]][C[i-1]] = True
    return res

def gcd(a, b):
    return a if b == 0 else gcd(b, a % b)

def layered_cycle_cover(n, m):
    deltas = [range(n) for _ in range(m)]
    for i in range(m):
        random.shuffle(deltas[i])
    for i in range(n):
        if gcd(sum(deltas[x][i] for x in range(m)), n) != 1: return []

    res = []
    used = [[[False]*n for _ in range(n)] for _ in range(m)]
    for i in range(n):
        u = 0
        C = []
        for _ in range(n):
            for j in range(m):
                v = (u+deltas[j][i]) % n
                assert not used[j][u][v]
                used[j][u][v] = True
                C.append(v)
                u = v
        res.append(C)
    return res

def gen_odd(big_cycles, small_cycles, n, m):
    S = [[]]
    skipped = set()
    for big in big_cycles:
        for small in small_cycles:
            day1 = []
            day2 = []
            for _ in range(100):
                start = random.randint(0, n*m-1)
                p1 = big[(start) % m]*n + small[(start) % (n*m)]
                p2 = big[(start-1) % m]*n + small[(start-1) % (n*m)]
                if n*m % 2 == 0: break
                if p1 not in skipped and p2 not in skipped:
                    S[0].append((p1, p2))
                    skipped.add(p1)
                    skipped.add(p2)
                    break
            else:
                return []
            for i in range(n*m - (n*m) % 2):
                p1 = big[(start+i) % m]*n + small[(start+i) % (n*m)]
                p2 = big[(start+i+1) % m]*n + small[(start+i+1) % (n*m)]
                day1.append((p1, p2))
                (day1, day2) = (day2, day1)
            S.append(day1)
            S.append(day2)
    return S

def odd_nm(n, m):
    big_cycles = small_cycles = S = None
    while not big_cycles: big_cycles = ham_cycle_cover(m)
    while not small_cycles: small_cycles = layered_cycle_cover(n, m)
    while not S: S = gen_odd(big_cycles, small_cycles, n, m)
    return S

def even_m(n, m):
    S = [[] for _ in range(n*(m-1))]
    for big_step in range(m-1):
        for small_step in range(n):
            for t1 in range(m):
                t2 = (big_step - t1) % (m-1)
                if t1 == t2: t2 = m-1
                if t2 < t1: continue
                for i1 in range(n):
                    i2 = (i1 + small_step) % n
                    S[n*big_step+small_step].append((t1*n+i1, t2*n+i2))
    return S

def even_n(n, m):
    def trans(p):
        if p < n*m/2: return p/(n/2) * n + p % (n/2)
        if p >= n*m/2: return (n*m-1-p)/(n/2) * n + n/2 + p % (n/2)
    return [filter(lambda (p1, p2): p1/n != p2/n,
                   [(trans(p1), trans(p2)) for (p1, p2) in day]) for day in even_m(n/2, 2*m)]

def format(t):
    return '%s%d' % (chr(random.choice([65,97]) + t / n), 1 + t % n)

(n,m) = map(int, raw_input().split())

if m % 2 == 0: S = even_m(n, m)
elif n % 2 == 0: S = even_n(n, m)
else: S = odd_nm(n, m)

import sys
first = True
for day in S:
    if day:
        if not first: print
        sys.stdout.write('  %s  ' %  ' \t'.join(['%s-%s' % (format(t1), format(t2)) for t1, t2 in day]))
        first = False
