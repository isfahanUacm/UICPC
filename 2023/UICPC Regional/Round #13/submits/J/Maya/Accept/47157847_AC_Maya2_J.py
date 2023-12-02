n, s = map(int, input().split())
l = []
for _ in range(n):
    a, b = input().split()
    b = int(b)
    l.append((b, a))
l = reversed(sorted(l))
ss = [] 
for i in l:
    if i[0] <= s:
        s -= i[0]
        ss.append(i[1])

if (s != 0):
    ss = []
ss = sorted(ss)
print(len(ss))
for i in ss:
    print(i)
