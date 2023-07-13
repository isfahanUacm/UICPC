#!/usr/bin/python3

n, m = map(int, input().split())
k, r = map(int, input().split())

l = [int(input()) for _ in range(n)]
c = [tuple(map(int, input().split())) for _ in range(n-1)]

INF = 10**15
dp = [[0]*m for _ in range(n)]

for ln in range(m):
    dp[n-1][ln] = l[n-1] + r*ln if ln*k <= l[n-1] else INF

for i in range(n-2, -1, -1):
    for ln in range(m):
        dp[i][ln] = INF
        for ll in range(m):
            if abs(ln-ll)*k <= l[i]:
                travel = r*abs(ln-ll) + l[i] + c[i][1]*(ll+1) + c[i][0]
                dp[i][ln] = min(dp[i][ln], travel + dp[i+1][ll])

print(dp[0][0])
