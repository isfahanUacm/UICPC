import sys
lines = sys.stdin.readlines()
li = []
cnt = {}
for line in lines:
    name, family = map(str, line.split())
    li.append((family, name))
    if name not in cnt:
        cnt[name] = 0
    cnt[name] += 1
li.sort()
for std in li:
    print(std[1] if cnt[std[1]] == 1 else std[1] + ' ' + std[0])
