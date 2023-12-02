def subsquare(n, m, a):
    return any(a % x == 0 and a / x <= max(n, m) for x in range(1, min(n,m)))

(n, m, a) = map(int, raw_input().split())
if a % n == 0 or a % m == 0:
    print 1
elif subsquare(n, m, a) or subsquare(n, m, n*m-a):
    print 2
else:
    print 3

