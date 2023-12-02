def bc(n, k):
    if k > n:
        return 0
    if k == 0:
        return 1
    if k > n/2:
        k = n - k
    c = 1
    for i in range(k):
        c = c * (n - i) // (i + 1)
    return c

def f(x,n,p):
    return bc(x,1) * bc(n,p-1)/bc(n+x,p)

n,k = map(int,input().split())

for i in range(n-1):
    a = int(input())

ans = 0
c = -1
for i in range(k+1):
    c *= -1
    ans += (c * bc(k,i)*(k-i)*(k-i-1)**(n-1))
    ans %= 1000000007

print(ans)


