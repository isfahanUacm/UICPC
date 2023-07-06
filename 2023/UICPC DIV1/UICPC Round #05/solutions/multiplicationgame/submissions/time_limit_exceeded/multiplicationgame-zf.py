#!/usr/bin/python3

def factor(n):
    pdiv = {}

    d = 2
    while d*d <= n:
        while n%d == 0:
            if d not in pdiv: pdiv[d] = 1
            else: pdiv[d] += 1
            n /= d
        d += 1

    if n > 1:
        pdiv[n] = 1

    return pdiv

for x in range(int(input())):
    n, play = input().split()

    pdiv = factor(int(n))

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
