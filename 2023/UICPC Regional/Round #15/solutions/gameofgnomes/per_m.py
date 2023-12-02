(n, m, k) = map(int, raw_input().split())

g = n/k
opt = 0
while g >= 0 and g*k + (k-1)*m >= n:
    rem = (n-g*k) % m
    opt = max(opt, ( g*(2*n - (g+m)*k) + (m+1)*n + rem*(rem-m) ) / 2)
    g -= 1
print opt
