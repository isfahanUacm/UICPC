n,k = map(int,input().split())
arr = list(map(int,input().split()))
mxSell = 0
mxProfit = 0
loans = 0
for i in range(n):
    loans += k
    arr[i]*=100
    arr[i]+=loans
    mxSell = max(mxSell,arr[i])
    mxProfit = max(mxProfit,mxSell-arr[i])
mxProfit-=k
if mxProfit>=0:
    print(mxProfit)
else:
    print(0)