import math
t = int(input())
for i in range(t):
    n, m = map(int, input().split())
    if n > m:
        n, m = m, n
    lg = math.log2(m+1)
    x = int(lg)
    res = max(0, n + m + 2 - 2 ** (x+1))
    for j in range(x+1):
        res += min(n+1, 2 ** j)
    print(res)
