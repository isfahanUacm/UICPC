h, w, n = map(int, input().split())
li = list(map(int, input().split()))
curw = 0
for i in range(n):
    if curw + li[i] <= w:
        curw += li[i]
    else:
        print('NO')
        exit(0)
    if curw == w:
        curw %= w
        h -= 1
    if not h:
        print('YES')
        exit(0)
print('NO')