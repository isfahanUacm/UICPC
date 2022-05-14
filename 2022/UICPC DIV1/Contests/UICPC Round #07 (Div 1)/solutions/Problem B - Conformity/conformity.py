n = int(input())
di = {}
mx = 0
for i in range(n):
    li = sorted(list(map(int, input().split())))
    tu = tuple(li)
    if tu not in di:
        di[tu] = 0
    di[tu] += 1
    if mx < di[tu]:
        mx = di[tu]
print(sum([mx for v in di.values() if v == mx]))
    