li = []
ans = []
for i in range(4):
    li += list(map(str, input().split()))
for i in range(12):
    for j in range(i + 1, 12):
        for k in range(j + 1, 12):
            a, b, c = li[i], li[j], li[k]
            flag = True
            for p in range(4):
                if (a[p] == b[p] and a[p] != c[p]) or (a[p] == c[p] and a[p] != b[p]) or (c[p] == b[p] and a[p] != c[p]):
                    flag = False
                    break
            if flag:
                ans.append((i + 1, j + 1, k + 1))
if ans:
    for v in ans:
        print(*v)
else:
    print('no sets')