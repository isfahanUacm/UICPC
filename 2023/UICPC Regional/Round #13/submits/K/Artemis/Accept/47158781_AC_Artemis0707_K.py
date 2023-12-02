c = [[0 for i in range(2501)] for j in range(2501)]
c[0][0] = 1
for i in range(1,2501):
    c[i][0] = 1
    for j in range(1,i+1):
        c[i][j] = (c[i-1][j-1] + c[i-1][j])%1000000007

n,k = map(int,input().split())

for i in range(n-1):
    a = int(input())

ans = 0
cc = -1
for i in range(k+1):
    cc *= -1
    ans += cc * c[k][i] * (k-i) * pow(k-i-1,n-1,1000000007)
    ans %= 1000000007

print(ans)


