import math
n = int(input())
a = list(map(int, input().split()))
b = list(map(int, input().split()))

ans = 1

for i in range(n):
    if a[i] / b[i] > 1:
        ans = max(ans,math.ceil(a[i] / b[i]))

print(ans)