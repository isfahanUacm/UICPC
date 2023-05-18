n = int(input())
a = [int(input()) for _ in range(n)]
l, r = 0, sum(a)
best = 0
for x in a:
    l += x*x
    r -= x
    best = max(best, l*r)
print(best)
