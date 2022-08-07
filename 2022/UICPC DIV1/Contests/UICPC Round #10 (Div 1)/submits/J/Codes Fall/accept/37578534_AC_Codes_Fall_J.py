t = int(input())
for _ in range(t):
    n, m = list(map(lambda x: int(x), input().split()))
    r = []
    w = []

    for i in range(m):
        rr, ww = list(map(lambda x: int(x), input().split()))
        r.append(rr)
        w.append(ww)

    if max(r) + max(w) > n:
        print("IMPOSSIBLE")

    else:
        print("R" * max(r), "W" * (n - max(r)), sep="")
