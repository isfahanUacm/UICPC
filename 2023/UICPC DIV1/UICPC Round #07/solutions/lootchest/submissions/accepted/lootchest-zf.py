#!/bin/python3

# This solution is used to generate the judge answers. It calculates everything
# as an exact fraction and outputs the answer with 20 digits of precision.

import fractions, decimal

LP, WP, G, L = map(int, input().split())
P = 0

def pr(x): return fractions.Fraction(x, 100)

em = {100:1/(1-pr(L))}
for i in range(99, -1, -1):
    em[i] = 1 + pr(L)*em[min(i+LP, 100)] + (1-pr(L))*(1-pr(i))*em[min(i+WP,100)]

ans = em[0]/pr(G)

decimal.getcontext().prec = 20
ans_f = decimal.Decimal(ans.numerator) / ans.denominator
print(ans_f)
