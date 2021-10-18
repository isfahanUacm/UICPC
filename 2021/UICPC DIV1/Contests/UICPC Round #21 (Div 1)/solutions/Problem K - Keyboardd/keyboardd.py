s = input()
t = input()
its = itt = tmps = tmpt = 0
res = set()
while its < len(s):
    rs = rt = 0
    while tmps < len(s) and s[its] == s[tmps]:
        tmps += 1
        rs += 1
    while tmpt < len(t) and t[itt] == t[tmpt]:
        tmpt += 1
        rt += 1
    if rs != rt:
        res.add(s[its])
    its = tmps
    itt = tmpt
print(''.join(res))
