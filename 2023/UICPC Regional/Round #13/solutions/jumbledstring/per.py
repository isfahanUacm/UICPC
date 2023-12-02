import math

def choose_inv(m):
    n = int(1 + math.sqrt(1+8*m))/2
    return n if n*(n-1)/2 == m else None

def solve(f00, f01, f10, f11):
    f0 = choose_inv(f00)
    f1 = choose_inv(f11)
    if f0 is None or f1 is None:
        return 'impossible'
    if f01 + f10 == 0:
        if f00 == 0: f0 = 0
        elif f11 == 0: f1 = 0
    n = f0 + f1
    if n*(n-1)/2 != f00 + f01 + f10 + f11:
        return 'impossible'
    ans = []
    for i in range(n):
        if f1 and f0 <= f10:
            ans += '1'
            f10 -= f0
            f1 -= 1
        else:
            ans += '0'
            f01 -= f1
            f0 -= 1
    return ''.join(ans) if f01 == 0 and f10 == 0 else 'impossible'

(a, b, c, d) = map(int, raw_input().split())
print solve(a, b, c, d)
