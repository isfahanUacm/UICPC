n, k = map(int, input().split())
has = [False] * 360
inp = list(map(int, input().split()))
li = [inp[0]]
while len(li):
    a = li.pop(0)
    if has[a]:
        continue
    has[a] = True
    for p in inp:
        if not has[abs(a-p)]:
            li.append(abs(a-p))
        if not has[(a+p) % 360]:
            li.append((a+p) % 360)
for b in list(map(int, input().split())):
    print('YES' if has[b] else 'NO')
