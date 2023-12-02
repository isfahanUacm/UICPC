(n, d) = map(int, raw_input().split())

F = sorted([map(int, raw_input().split()) for _ in range(n)], key = lambda x: -x[1])
e = F[0][1]+1
H = [0]*(e+1)
ans = 0
for (l, w, h) in F:
    while e > 2*w:
        e -= 1
        H[e] = max(H[e], H[e+1])
    ok = 0
    for p in range(w+1, 2*w+1):
        hp = H[p] if p <= e else 0
        ok |= hp + l > d
        H[p-w] = max(H[p-w], hp + h)
    ans += ok

print ans
