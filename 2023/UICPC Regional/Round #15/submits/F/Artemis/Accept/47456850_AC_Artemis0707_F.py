n = int(input())
a = list(map(int, input().split()))

d = 0
t = 10000000
for i in range(n-2):
    if max(a[i], a[i+2]) < t:
        t = max(a[i], a[i+2])
        d = i+1

print(d, t)
