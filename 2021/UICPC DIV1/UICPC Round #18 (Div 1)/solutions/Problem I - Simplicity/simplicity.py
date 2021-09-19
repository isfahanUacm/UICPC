s = input()
mp = {}
for a in s:
    if a not in mp:
        mp[a] = 1
    else:
        mp[a] += 1
li = sorted(list(mp.values()))
if len(mp) <= 2:
    print(0)
else:
    print(sum(li[:len(li)-2]))


