#!/usr/bin/env python3
n = int(input())
scores = [tuple(map(int, input().strip().split('-'))) for _ in range(n)]
x = y = 0
for (i, (a, b)) in enumerate(scores):
    if (a+b+1)//2 % 2:
        (a, b) = (b, a)
    if a < x or b < y or a > 11 or b > 11 or (a, b) == (11, 11) or (max(x, y) == 11 and (x, y) != (a, b)):
        print('error', i+1)
        break
    (x, y) = (a, b)
else:
    print('ok')

