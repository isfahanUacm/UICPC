# Gale-Shapley
n,m=map(int,raw_input().split())
b,r=map(int,raw_input().split())
event=[map(int,raw_input().split()) for k in range(r)]
first = [ [b] * m for _ in range(n) ]
total = [ [0] * m for _ in range(n) ]
cur = [(0, -1)] * n
for si, ki, ti in event:
    ki -= 1; ti -= 1
    ps, pt = cur[ki]
    if ti >= 0:
        first[ki][ti] = min(first[ki][ti], si)
    if pt >= 0:
        total[ki][pt] += si - ps
    cur[ki] = (si, ti)
for k in range(n):
    ps, pt = cur[k]
    if pt >= 0:
        total[k][pt] += b - ps

queue = [None]*n
for k in range(n):
    queue[k] = sorted(range(m), key=lambda i: -first[k][i])

if n > m:
    print 'impossible'
else:
    match=[None]*m
    ans=[None]*n
    work=range(n)
    while work:
        k = work[-1]
        del work[-1]
        while queue[k]:
            t = queue[k][-1]
            del queue[k][-1]
            pre = match[t]
            if pre is None:
                match[t] = k
                ans[k] = t + 1
                break
            elif total[k][t] < total[pre][t]:
                match[t] = k
                ans[k] = t + 1
                ans[pre] = None
                work += [pre]
                break
    print ' '.join(map(str, ans))
