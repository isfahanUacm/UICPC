size = input()

n = int(size.split(" ")[0])
m = int(size.split(" ")[1])

edge = [[] for i in range(n)]
force_edge = [[] for i in range(n)]

for i in range(m):
    s = input()
    u = int(s.split(" ")[0])
    v = int(s.split(" ")[0])

    if u<0: force_edge[-1*(u+1)].append(v-1)
    else: edge[u-1].append(v-1)

res = set()

def solve(node, k):
    if k > 1: return

    if k==0:
        for t in edge[node]:
            if t==0: continue
            if(len(force_edge[t])): res.add(t)

    if k==0:
        for t in edge[node]:
            if t==0: continue
            solve(t, k+1)

    for t in force_edge[node]:
        if t==0: continue
        if(len(force_edge[t])==0): res.add(t)

    for t in force_edge[node]:
        if t==0: continue
        solve(t, k) 

if(len(force_edge[0])): res.add(0)
solve(0, 0)

print(len(res))