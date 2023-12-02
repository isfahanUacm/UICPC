import random

# Randomly tries X points within distance R from best point so far,
# where R decreases linearly. Repeats this solution Y times. This takes
# O(XY). Y = 1 solutions seem to fail with some probability, especially
# if k is small.

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

(n, m, k) = list(map(int, raw_input().split()))
X = 10000
Y = 30
lo = max(0, n//k - m + m//k)
hi = n//k + 1

xb = 0
best = 0
for j in range(0, Y):
    x_best = lo
    ans = f(x_best)
    r_start = 1.1 * (hi-lo)
    r_stop = -0.4 * r_start
    
    for i in range(0,X):
        r = int(float(i)/X * r_stop + (1 - float(i)/X) * r_start)
        r = max(0, r)
        lo_x = max(lo, x_best - r)
        hi_x = min(hi, x_best + r)

        x_temp = random.randint(lo_x, hi_x)
        if x_temp == x_best:
            if random.randint(0,1) == 0:
                x_temp += 1
            else:
                x_temp -= 1
        temp = f(x_temp)
        if temp > ans:
            ans = temp
            x_best = x_temp
    if ans > best:
        xb = x_best
        best = ans

print(best)
