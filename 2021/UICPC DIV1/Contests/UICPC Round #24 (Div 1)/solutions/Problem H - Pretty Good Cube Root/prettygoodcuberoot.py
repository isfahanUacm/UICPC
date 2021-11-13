import sys


def fun(i, n):
    d = i*i*i
    if d < n:
        return -1
    else:
        return 1


lines = sys.stdin.readlines()
for line in lines:
    n = int(line)
    lo, hi = 0, n
    while lo < hi:
        mi = (lo+hi)//2
        dd = fun(mi, n)
        if dd == -1:
            lo = mi + 1
        else:
            hi = mi - 1
    li = []
    for i in range(lo-1, lo+2):
        li.append((abs(i*i*i-n), i))
    li.sort()
    print(li[0][1])