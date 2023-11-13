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
r = 10**9

while r - l > 1:
    m = (r+l)//2
    f1 = f(m,n,p)
    f2 = f(m+1,n,p)
    f3 = f(m-1,n,p)

    if f1 > f2 and f1 > f3:
        break

    if f(m,n,p) < f(m+1,n,p):
        l = m
    else:
        r = m-1

print(max(f(m-1,n,p),f(m,n,p),f(m+1,n,p)))
