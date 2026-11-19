n =int(input())
k1 = int(input())
info1 = [list(map(int,input().split())) for _ in range(k1)]
k2 = int(input())
info2 = [list(map(int,input().split())) for _ in range(k2)]

s = 0
for i1, j1, d1 in info1:
    for i2, j2, d2 in info2:
        if i1 == j2 and j1 == i2:
            s += d1*d2
print(s)