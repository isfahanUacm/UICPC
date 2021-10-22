mp = {}
n = int(input())
dira = [0, 2018, 0, -2018, 1118, 1680, -1118, -1680, -1118, 1680, -1680, 1118]
dirb = [2018, 0, -2018, 0, 1680, 1118, -1680, -1118, 1680, -1118, 1118, -1680]
for i in range(n):
    a, b = map(int, input().split())
    mp[(a, b)] = False
res = 0
for k in mp:
    a, b = k[0], k[1]
    for i in range(12):
        if (a + dira[i], b + dirb[i]) in mp and not mp[(a + dira[i], b + dirb[i])]:
            res += 1
    mp[(a, b)] = True
print(res)