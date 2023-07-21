#!/bin/python3

n = int(input())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = []
cnt = {x:0 for x in a}
diff = 0

def upd(x, d):
    global diff
    if cnt[x] == 0: diff += 1
    cnt[x] += d
    if cnt[x] == 0: diff -= 1

for i in range(n-1):
    upd(a[i], 1)
    upd(b[i], -1)
    if diff == 0: ans.append(i)

def dump(l):
    out = []
    ia = 0
    for i in range(n):
        out.append(str(l[i]))
        if ia < len(ans) and i == ans[ia]:
            out.append("#")
            ia += 1
    print(" ".join(out))

# dump(a)
dump(b)
