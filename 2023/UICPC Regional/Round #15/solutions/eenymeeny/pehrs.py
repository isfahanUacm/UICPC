def josephus(l,k):
    i = 0
    while (len(l)) > 1:
        i = (i+k-1) % len(l)
        yield(l.pop(i))
    yield l[0]

steps = len(raw_input().split())
i = int(raw_input())
kids = []
for k in range(0, i):
    kids +=[raw_input()]

res = []
for i in josephus(kids, steps):
    res +=[i]

print len(res[::2])
for i in res[::2]:
    print i
print len(res[1::2])
for i in res[1::2]:
    print i