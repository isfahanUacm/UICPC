from bisect import bisect

n, v = map(int, input().split())
t = list(map(int, input().split()))
a = list(map(int, input().split()))

vec = []
for i in range(n):
    if v * t[i] < abs(a[i]):
        continue
    vec.append((v*t[i] - a[i], v*t[i] + a[i]))
vec.sort()

buckets = []
for p in vec:
    i = bisect(buckets, p[1])
    if i == len(buckets): buckets.append(0)
    buckets[i] = p[1]

print(len(buckets))
