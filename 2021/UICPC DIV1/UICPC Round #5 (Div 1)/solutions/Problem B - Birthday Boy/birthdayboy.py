days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
sumdays = [31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365]
n = int(input())
li = []
for i in range(n):
    a, b = map(str, input().split())
    li.append(b)
li.sort()
mx = 0
candid = []
for i in range(1, n):
    m2, d2 = map(int, li[i].split('-'))
    m1, d1 = map(int, li[i-1].split('-'))
    v = 0
    if m1 == m2:
        v = d2 - d1 - 1
    else:
        v = (sumdays[m2-2] - sumdays[m1-1]) + (days[m1-1] - d1) + d2 - 1
    if v == mx:
        if d2 - 1 == 0:
            candid.append('{:0>2d}'.format((m2+10) % 12 + 1) + '-' + '{:0>2d}'.format(days[m2-2]))
        else:
            candid.append('{:0>2d}'.format(m2) + '-' + '{:0>2d}'.format(d2-1))
    elif v > mx:
        mx = v
        if d2 - 1 == 0:
            candid = ['{:0>2d}'.format((m2+10) % 12 + 1) + '-' + '{:0>2d}'.format(days[m2-2])]
        else:
            candid = ['{:0>2d}'.format(m2) + '-' + '{:0>2d}'.format(d2-1)]
m2, d2 = map(int, li[0].split('-'))
m1, d1 = map(int, li[n-1].split('-'))
v = 0
if m1 == m2:
    v = 365 - (d1 - d2) - 1
else:
    v = 365 - sumdays[m1-1] + (sumdays[m2-2] if m2 >= 2 else 0) + (days[m1-1] - d1) + d2 - 1
if v == mx:
    if d2 - 1 == 0:
        candid.append('{:0>2d}'.format((m2+10) % 12 + 1) + '-' + '{:0>2d}'.format(days[m2-2]))
    else:
        candid.append('{:0>2d}'.format(m2) + '-' + '{:0>2d}'.format(d2-1))
elif v > mx:
    mx = v
    if d2 - 1 == 0:
        candid = ['{:0>2d}'.format((m2+10) % 12 + 1) + '-' + '{:0>2d}'.format(days[m2-2])]
    else:
        candid = ['{:0>2d}'.format(m2) + '-' + '{:0>2d}'.format(d2-1)]
if len(candid) == 1:
    print(candid[0])
else:
    candid.append('10-27')
    candid.sort()
    it = candid.index('10-27')
    while candid[it] == '10-27':
        it = (it + 1) % len(candid)
    print(candid[it])
