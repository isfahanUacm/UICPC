import random


# Does a bunch of ternary searches on random intervals.
# Also makes sure to cover the endpoints sometimes.


def f(x):
    if x > n//k or n - x*k > m*(k-1) or x < 0:
        return -1
    result = x*n - (k*x*(x-1))//2
    n2 = n - x*k
    k2 = n2//m + 1
    x2 = n2 - m*(n2//m)
    result += x2*n2 - (k2*x2*(x2-1))//2
    n3 = n2 - x2*k2
    k3 = k2-1
    x3 = m-x2
    result += x3*n3 - (k3*x3*(x3-1))//2
    return result

def TS(l,r,d):
    res = max(f(l),f(r))
    
    while l < r-3:
        mid1 = (2*l + r)//3
        mid2 = (l + 2*r)//3
        res1 = f(mid1)
        res2 = f(mid2)
        res = max(res, res1, res2)
        if res1 < res2:
            l = mid1
        else:
            r = mid2
    for i in range(l-d,l+d):
        res = max(res, f(i))
    return res
        

(n, m, k) = list(map(int, raw_input().split()))
X = 10**4
lo = max(0, n//k - m + m//k)
hi = n//k + 1
ans = 0
for i in range(0,X):
    l = random.randint(lo,hi)
    r = random.randint(lo,hi)

    if random.randint(0,4) == 0:
        l = lo
    if random.randint(0,4) == 0:
        r = hi

    if l > r:
        (l,r) = (r,l)
    ans = max(ans,TS(l,r,5))

print(ans)

