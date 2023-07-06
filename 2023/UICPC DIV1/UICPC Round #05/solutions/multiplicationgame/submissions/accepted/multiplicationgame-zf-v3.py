#!/usr/bin/python3

# presieves for faster factoring

def sieve(n):
    p = [True for i in range(n+1)]
    i = 2
    while i*i <= n:
        if p[i]:
            for j in range(i*i, n+1, i):
                p[j] = False
        i += 1
    return [i for i in range(2,n+1) if p[i]]

def factor(n, primes):
    pdiv = {}

    for d in primes:
        if d*d > n: break;
        while n%d == 0:
            if d not in pdiv: pdiv[d] = 1
            else: pdiv[d] += 1
            n /= d
        d += 2 # incrementing by 1 only makes it run too slow!

    if n > 1:
        pdiv[n] = 1

    return pdiv

primes = sieve(50000)
for x in range(int(input())):
    n, play = input().split()

    pdiv = factor(int(n), primes)

    if len(pdiv) == 1:
        winner = 1-(list(pdiv.values())[0]%2)
    elif len(pdiv) >= 3:
        winner = -1
    else:
        mn = min(pdiv.values())
        mx = max(pdiv.values())
        if mn == mx: winner = 1
        elif mn+1 == mx: winner = 0
        else: winner = -1

    out = {-1:"tie"}
    if play == "Alice": out[0], out[1] = "Alice", "Bob"
    else: out[0], out[1] = "Bob", "Alice"

    print(out[winner])
