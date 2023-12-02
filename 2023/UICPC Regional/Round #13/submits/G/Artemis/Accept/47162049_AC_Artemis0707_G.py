import math

l, n = map(int, input().split())

mn = 100000000
ls = []
for i in range(n):
    name, p, c, t, r = input().split(',')
    r = int(r)
    t = int(t)
    c = int(c)
    p = int(p)
    
    q = c * t
    k = (r + t) * 10080 / math.gcd(r + t, 10080) 
    total = q * k / (r + t)
    avg = total / (k / 10080)
    
    if avg >= l and p == mn:
        ls.append(name)
    elif avg >= l and p < mn:
        ls = []
        ls.append(name)
        mn = p
        
if len(ls) == 0:
    print('no such mower')
else:
    for i in ls:
        print(i)