import sys

def cdp(i, j, n, k):
    global dp
    if i == n:
        return 1
    if dp[i][j] != -1:
        return dp[i][j]
    dp[i][j] = cdp(i + 1, j, n, k) + (cdp(i+1, j-1, n, k) if j > 0 else 0) + (cdp(i+1, j+1, n, k) if j < k else 0)
    # print(i, j, dp[i][j])
    return dp[i][j]

lines = sys.stdin.readlines()
for line in lines:
    k, n = map(int, line.split())
    dp = [[-1 for i in range(10)] for j in range(103)]
    ans = 0
    for i in range(k + 1):
        ans += cdp(1, i, n, k)
    # print(dp)
    # print(ans)
    print('%.7f' % (100 * ans / ((k + 1) ** n)))
