#!/usr/bin/env python3
N = int(input())
H = [int(x) for x in input().split()]

ans = 0
for i in [i for i in range(1, N-1) if H[i] > H[i-1] and H[i] >= H[i+1]]:
    l, r = i, i
    while 0 <= l - 1 and H[l - 1] <= H[l]: l = l - 1
    while r + 1 < N and H[r] >= H[r + 1]: r = r + 1
    ans = max(ans, min(H[i] - H[l], H[i] - H[r]))
print(ans)
