#!/usr/bin/env python2
MOD = 10**9 + 7

(n, k) = map(int, raw_input().split())

def exp(b, e):
    r = 1
    while e:
        if e & 1: r = (r * b) % MOD
        e >>= 1
        b = (b * b) % MOD
    return r

ans = 0
binom = 1
for t in range(k):
    ans = (ans + binom * (k-t) * exp(k-t-1, n-1)) % MOD
    binom = -binom * (k-t) / (t+1)

print ans
