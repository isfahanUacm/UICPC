import sys

lines = sys.stdin.readlines()
it = 0
while True:
    n = int(lines[it])
    it += 1
    if n == 0:
        break
    val = []
    for i in range(n):
        val.append(float(lines[it + i]))
    it += n
    dp = [[0]*2] * n
    tax_co = 0.97
    dp[0][0], dp[0][1] = 100000, int(100000 / val[0] * tax_co)
    for i in range(1, n):
        dp[i][0] = max(dp[i-1][0], int(dp[i-1][1] * val[i] * tax_co))
        dp[i][1] = max(dp[i-1][1], int(dp[i-1][0] / val[i] * tax_co))
    print('%.02lf' % (dp[n-1][0] / 100))
