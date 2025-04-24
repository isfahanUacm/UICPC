N,M=map(int,input().split())

terms = [list(map(int,t.split(' * '))) for t in input().replace('-', '+').split(' + ')]
terms_flat = sum(terms, [])
terms_idx = []
terms_even = []

flip = []
base = 0
for i, term in enumerate(terms):
    n_even = sum(1 - t % 2 for t in term)
    if n_even == 0:
        base = 1 - base
    terms_even.append(n_even)
    terms_idx.extend([i] * len(term))

bs = ['even','odd'][base]
bn = ['even','odd'][1 - base]
print(bs)
for _ in range(M):
    f,t=map(int,input().split())
    if terms_flat[f - 1] % 2 == t % 2:
        print(bs)
        continue
    ti=terms_idx[f-1]
    pte=terms_even[ti]
    terms_even[ti]+= (1 - t % 2) - (1 - terms_flat[f - 1] % 2)
    if (pte == 0) != (terms_even[ti] == 0):
        bn, bs = bs, bn
    terms_flat[f - 1] = t
    print(bs)