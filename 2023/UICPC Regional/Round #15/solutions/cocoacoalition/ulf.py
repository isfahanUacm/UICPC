#!/usr/bin/env python3
def f(n, m, a):
    for i in range(1, n):
        if a%i == 0 and a//i < m:
            return True
    return False

(n, m, a) = map(int, input().split())
if a%m == 0 or a%n == 0:
    print(1)
elif f(n, m, a) or f(n, m, n*m-a):
    print(2)
else:
    print(3)
