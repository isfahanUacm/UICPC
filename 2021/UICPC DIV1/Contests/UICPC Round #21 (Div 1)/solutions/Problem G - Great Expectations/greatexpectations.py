#!/usr/bin/env python3
N, R, m = [int(x) for x in input().split()]

tricks = [(0, 0.0, 0)]
for _ in range(m):
    t, p, l = input().split()
    tricks.append((int(t), float(p), int(l)))
tricks.sort()

hi = 50000*R
lo = 0

while hi - lo > 1e-7:
    mid = (hi + lo)/2

    dp = [[mid]*(R+1) for _ in range(m+1)]

    for i in range(R):
        if i + (N - tricks[-1][0]) < R:
            dp[m][i] = N - tricks[-1][0]

    for ti in reversed(range(1, m+1)):
        diff = tricks[ti][0] - tricks[ti-1][0]
        for j in range(R):
            # What is the time you take immediately after completing trick t +
            # potentially eating the extra time?
            p = tricks[ti][1]
            lost_time = tricks[ti][2]
            if j + diff + lost_time <= R:
                dp[ti-1][j] = min(dp[ti-1][j], 
                        p*(diff + dp[ti][j+diff]) + 
                        (1-p)*(diff + min(mid, lost_time + dp[ti][j+diff+lost_time])))
            elif j + diff <= R:
                dp[ti-1][j] = min(dp[ti-1][j], 
                        diff + 
                        p*dp[ti][j+diff] + 
                        (1-p)*mid)

    if dp[0][0] + 1e-9 < mid:
        hi = mid
    else:
        lo = mid
print(f"{mid:.6f}")
