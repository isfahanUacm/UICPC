n, c = map(int, input().split())
if n == 1:
    a = int(input())
    print(1 if a <= c else 0)
    exit(0)
li = list(map(int, input().split()))
m = 0
for i in range(n):
    t = 0
    s = 0
    for j in range(i, n):
        if li[j]+s <= c:
            s += li[j]
            t += 1
    m = max(m, t)
print(m)
