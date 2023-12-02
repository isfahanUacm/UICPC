

memo = {}
def ans(X, Y, Z):
    X = sorted(X, reverse=True)
    Y = sorted(Y, reverse=True)
    while Y and Y[-1] == 0: Y.pop()
    while X and X[-1] == 0: X.pop()
    key = (tuple(X), tuple(Y))
    if not Y: return 1.0
    if not Z: return 0.0 # a bit slow, should give up as soon as sum(Y) > Z
    if key not in memo:
        res = 0.0
        for i in range(len(X)):
            X[i] -= 1
            res += ans(X, Y, Z-1)
            X[i] += 1
        for i in range(len(Y)):
            Y[i] -= 1
            res += ans(X, Y, Z-1)
            Y[i] += 1
        res /= len(X) + len(Y)
        memo[key] = res
    return memo[key]


(_, _, Z) = map(int, raw_input().split())
X = map(int, raw_input().split())
Y = map(int, raw_input().split())
print ans(X, Y, Z)
