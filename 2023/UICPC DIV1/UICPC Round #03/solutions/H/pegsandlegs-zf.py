#!/usr/bin/python3

L, P = map(int, input().split())

hit = set()
dp = {}

for i in range(L+P):
    l = input().split()
    if i < L:
        dp[i] = (float(l[0]), 0.0)
    else:
        pl, pr = float(l[0]), float(l[1])
        il, ir = int(l[2])-1, int(l[3])-1
        dp[i] = (pl*dp[il][0] + pr*dp[ir][0], 1.0-pl-pr + pl*dp[il][1] + pr*dp[ir][1])
        hit.add(il)
        hit.add(ir)

best = 0.0
for i in dp:
    if i not in hit:
        best = max(best, dp[i][0]/(1.0-dp[i][1]))

print("{0:.10f}".format(best))
