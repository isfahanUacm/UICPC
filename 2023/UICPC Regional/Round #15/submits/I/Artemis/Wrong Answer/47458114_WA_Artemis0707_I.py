n,m,s,d = map(int,input().split())
cs = list(map(int,input().split()))
c = {}
for i in range(s):
    c[i] = [cs[i],0]

c = dict(sorted(c.items(),key=lambda x: x[1][0]))
#print(c)
i  = 0
while n>0:
    if c[i][0] + c[i][1]  < d:
        n -= 1
        c[i][1] += 1
    elif i < s-1:
        i += 1
    else:
        break

sm = 0
while i < s:
    sm += c[i][0]
    i+=1
#print(c)
if sm >= m:
    c = dict(sorted(c.items(),key=lambda x: x[0]))
    for i in range(s):
        print(c[i][1],end=' ')
else:
    print('impossible')
