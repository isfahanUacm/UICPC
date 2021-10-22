n, p = map(int, input().split())
li = list(map(int, input().split()))
mx, s = 0, 0
for i in range(n):
    s += li[i] - p
    mx = max(s, mx)
    s = 0 if s < 0 else s
print(mx)