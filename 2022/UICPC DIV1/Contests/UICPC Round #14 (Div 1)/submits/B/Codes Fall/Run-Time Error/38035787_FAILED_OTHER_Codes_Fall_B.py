x_r = []
y_r = []
for i in range(1000002):
    x_r.append(0)
    y_r.append(0)


def calc(nn, a, r):
    r += 1
    n = nn
    for i in range(a, n+1):
        nn = n - i
        if nn == 0:
            x_r[r] += 1
            return
        calc(nn, a, r)


def calc_y(nn, a, r):
    r += 1
    n = nn
    for i in range(a, n+1):
        nn = n - i
        if nn == 0:
            y_r[r] += 1
            return
        calc_y(nn, a, r)


n, x, y = list(map(int, input().split()))


calc(n, x, 0)
calc_y(n, y, 0)

plus = 0
for i, j in zip(x_r, y_r):
    plus += i * j

print(plus)
