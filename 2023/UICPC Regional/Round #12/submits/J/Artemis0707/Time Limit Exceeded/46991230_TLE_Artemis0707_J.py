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

n,p = map(int,input().split())

l = 0
r = 10**18

while r-l > 2:
    m1 = l + (r-l)//3
    m2 = r - (r-l)//3
    if f(m1,n,p) < f(m2,n,p):
        l = m1
    else:
        r = m2

ans = 0
for i in range(l,r+1):
    ans = max(ans,f(i,n,p))

print(ans)
