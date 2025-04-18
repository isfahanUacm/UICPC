n, k = map(int, input().split())
p = list(map(int, input().split()))

ans = n
for i in range(k):
    ans += p[i] * (2 ** (k - 1 - i))

print(ans)