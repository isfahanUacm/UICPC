import sys


def is_peak(i: int, n: int):
    global li
    tmpr = tmpl = li[i]
    for j in range(1, n):
        if li[i+j] > tmpr or li[i-j] > tmpl:
            return False
        tmpr = li[i+j]
        tmpl = li[i-j]
    return True


def is_valley(i: int, m: int):
    global li
    tmpr = tmpl = li[i]
    for j in range(1, m):
        if li[i + j] < tmpr or li[i - j] < tmpl:
            return False
        tmpr = li[i + j]
        tmpl = li[i - j]
    return True


s, n, m = map(int, input().split())
li = []
for line in sys.stdin.readlines():
    li += list(map(int, line.split()))
p = v = 0
for i in range(n-1, s-n+1):
    if is_peak(i, n):
        p += 1
for i in range(m - 1, s - m + 1):
    if is_valley(i, m):
        v += 1
print(p, v)
