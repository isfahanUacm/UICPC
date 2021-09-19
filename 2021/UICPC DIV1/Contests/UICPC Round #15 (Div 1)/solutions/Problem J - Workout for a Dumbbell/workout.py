li = list(map(int, input().split()))
li = [(li[i*2], li[i*2 + 1]) for i in range(10)]
# print(li)
oth = []
for i in range(10):
    u, r, st = map(int, input().split())
    oth.append((u, r, st))
res = 0
for i in range(3):
    for j in range(10):
        othu, othr, otht = oth[j][0], oth[j][1], oth[j][2]
        if res >= otht and (res - otht) % (othu + othr) <= othu:
            res += othu - ((res - otht) % (othu + othr))
        otht = (res - ((res - otht) % (othu + othr))) if res >= otht else otht
        otht = res + li[j][0] if (res + li[j][0] > otht + othu + othr or (res < otht < res + li[j][0] <= otht + othu + othr)) else otht
        res += li[j][0] + li[j][1]
        oth[j] = (othu, othr, otht)
print(res-li[9][1])