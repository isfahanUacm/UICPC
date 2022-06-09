k = int(input())
a, b, ans = 10000, 0, 0
for i in range(k):
    b = int(input())
    if b < a:
        ans += 1
    a = b
print(ans)