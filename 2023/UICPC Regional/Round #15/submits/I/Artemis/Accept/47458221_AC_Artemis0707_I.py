n,m,s,d = map(int,input().split())
cs = list(map(int,input().split()))
c = {}
for i in range(s):
    c[i] = [cs[i],0]

c = dict(sorted(c.items(),key=lambda x: x[1][0]))
kys = list(c.keys())
i = 0
while n>0:
    if c[kys[i]][0] + c[kys[i]][1]  < d:
        n -= 1
        c[kys[i]][1] += 1
    elif i < s-1:
        i += 1
    else:
        break

sm = 0
i = 0
while i < s:
    if c[i][1] == 0:
        sm += c[i][0]
    i += 1
#print(c)
if sm >= m:
    c = dict(sorted(c.items(),key=lambda x: x[0]))
    for i in range(s):
        print(c[i][1],end=' ')
else:
    print('impossible')

