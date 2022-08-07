t = int(input())

for _ in range(t):
    n, m = map(int, input().split())

    critics = [tuple(map(int, input().split())) for i in range(m)]

    r = max(c[0] for c in critics)
    w = max(c[1] for c in critics)

    if r + w > n:
        print("IMPOSSIBLE")

    else:
        print('R' * r + 'W' * (n - r))

