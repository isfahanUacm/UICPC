#!/usr/bin/python3
n = int(input())

x, y = [], []

for _ in range(n):
    a, b = map(int, input().split())
    x.append(a)
    y.append(b)

def process(l):
    l.sort()
    totL, totR = 0, sum(x-l[0] for x in l)
    ans = totR

    for i in range(1, len(l)):
        totL += i*(l[i] - l[i-1])
        ans += totL
        if i + 1 < len(l):
            totR -= (n-i)*(l[i]-l[i-1])
            ans += totR
    return ans//2

print(process(x) + process(y))
