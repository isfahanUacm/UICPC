#CPP ARRRRRRRRRRrrrrrrrrrrr

n, m = map(int, input().split())
adj = list()
for i in range(n+1):
    adj.append(list())
    
mark = (n+1)*[False]
component = list()
for i in range(m):
    u, v = map(int, input().split())
    adj[u].append(v)
    adj[v].append(u)

def DFS(v):
    mark[v] = True
    component.append(v)
    for u in adj[v]:
        if not mark[u]:
            DFS(u)

res = 0
for i in range(1, n+1):
    if mark[i]:
        continue
    component.clear()
    DFS(i)
    
    res += len(component) * (len(component) - 1) // 2

print(res/(n*(n-1)//2))
