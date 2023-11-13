#!/usr/bin/env python3
import sys

def phi(m):
    res = 1
    p = 2
    while p*p <= m:
        if m % p == 0:
            res *= p-1
            m //= p
            while m % p == 0:
                res *= p
                m //= p
        p += 1
    if m > 1:
        res *= m-1
    return res


def expmod(b, e, m):
    res = 1
    while e:
        if e % 2: res = (res * b) % m
        e //= 2
        b = (b*b) % m
    return res

def expo_trunc(n):
    return n if n < 3 else 9 if n == 3 else 99

def expo_mod_m(n, m):
    if m == 1: return 0
    if n == 1: return 1
    m2 = phi(m)
    e = expo_trunc(n-1)
    if e == 99:
        e = m2 + expo_mod_m(n-1, m2)
    return expmod(n, e, m)


(n, m) = map(int, sys.stdin.read().split())
print(expo_mod_m(n, m))
