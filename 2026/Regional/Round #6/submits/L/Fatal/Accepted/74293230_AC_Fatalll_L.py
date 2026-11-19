n = int(input())
mod = 1006903069

k1 = int(input())
info1 = {}
for _ in range(k1):
    i, j, d = map(int, input().split())
    info1[(i, j)] = d

k2 = int(input())
info2 = {}
for _ in range(k2):
    i, j, d = map(int, input().split())
    info2[(i, j)] = d

s = 0
for i1, j1 in info1.keys():
    if (j1, i1) in info2:
        s += ((info1[(i1, j1)] * info2[(j1, i1)]) % mod)
        s %= mod
print(s)