n = int(input())
dp = [[] for i in range(n+1)]

stores = []
for i in range(n):
    ti, hi = map(int, input().split())
    cmp = (ti + hi)/2
    stores.append([cmp,[ti,hi]])
stores.sort()
#print(stores)
dp[0].append([0,0])
for i in range(1,n+1):
    ti, hi = stores[i-1][1][0], stores[i-1][1][1]
    for state in dp[i-1]:
        endtime = state[0]  + ti
        if endtime<=hi:
            dp[i].append([endtime,state[1]+1])
    for state in dp[i-1]:
        dp[i].append(state)
    #dp[i].sort()
    #print(dp[i])
#print(dp[n])
mx = 0
for state in dp[n]:
    mx = max(mx, state[1])
print(mx)