n = int(input())
mp = {}
for i in range(n):
    cand = input()
    asos = input()
    mp[cand] = [asos, 0]
m = int(input())
mx = 0
res = ''
flag = False
for i in range(m):
    c = input()
    if c not in mp:
        continue
    mp[c][1] += 1
    if mp[c][1] == mx:
        flag = False
    elif mp[c][1] > mx:
        mx = mp[c][1]
        res = mp[c][0]
        flag = True
print(res if flag else 'tie')