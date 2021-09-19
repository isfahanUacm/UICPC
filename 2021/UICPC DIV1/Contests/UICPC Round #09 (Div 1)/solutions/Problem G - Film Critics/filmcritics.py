n, m, k = map(int, input().split())
a = list(map(int, input().split()))
a = sorted([(a[i], i+1) for i in range(n)])
if k % m:
    print('impossible')
    exit(0)
p = k // m
ps = a[n-p:]
ng = a[:n-p]
ng.reverse()
res = []
itp, itn, ip = 0, 0, 0
val = 0
for i in range(n):
    if i == 0:
        if len(ps):
            itp += 1
            res.append(ps[0][1])
            val += m
        else:
            print('impossible')
            exit(0)
    elif itp != p and ps[itp][0] >= val / i:
        res.append(ps[itp][1])
        itp += 1
        val += m
    elif itn != n-p and ng[itn][0] < val / i:
        res.append(ng[itn][1])
        itn += 1
    else:
        print('impossible')
        exit(0)
print(' '.join([str(aa) for aa in res]))