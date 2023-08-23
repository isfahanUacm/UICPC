n = int(input())
a = list(map(int, input().split()))
a = sorted(a, reverse=True)
ans =0
for i in range(n):
    if i % 3 ==2:
        ans += a[i]
print(ans)