n, k = map(int, input().split())
li = list(map(int,input().split()))
s = 0
p = 0
loans = 0
for i in range(n):
    loans += k
    li[i] *= 100
    li[i] += loans
    s = max(s, li[i])
    p = max(p, s - li[i])
p -= k
print(p if p >= 0 else 0)
