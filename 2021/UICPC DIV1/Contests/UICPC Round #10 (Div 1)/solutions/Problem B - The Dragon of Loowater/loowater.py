while True:
    n, m = map(int, input().split())
    if n == 0 and m == 0:
        break
    heads = []
    knights = []
    for i in range(n):
        d = int(input())
        heads.append(d)
    for i in range(m):
        h = int(input())
        knights.append(h)
    if n > m:
        print('Loowater is doomed!')
        continue
    heads.sort()
    knights.sort()
    j = 0
    i = 0
    res = 0
    while i < len(heads) and j < len(knights):
        if knights[j] >= heads[i]:
            res += knights[j]
            i += 1
        j += 1
    if i < len(heads):
        print('Loowater is doomed!')
    else:
        print(res)
