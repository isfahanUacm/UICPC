n = int(raw_input())
par = [0] + map(int, raw_input().split())
flow = map(int, raw_input().split())

children = [[] for _ in range(n)]
for i in range(1, n):
    par[i] -= 1
    children[par[i]].append(i)

order = [0]
for i in range(n):
    u = order[i]
    order.extend([v for v in children[u]])

minflow = [1]*n
for u in reversed(order):
    minflow[u] = max(1, flow[u], sum(minflow[v] for v in children[u]))

c_minrem = [sum(minflow[v] for v in children[u] if flow[v] <= 0) for u in range(n)]
c_unknown = [sum(1 for v in children[u] if flow[v] <= 0) for u in range(n)]
c_sum = [sum(flow[v] for v in children[u] if flow[v] > 0) for u in range(n)]

Q = []
def assign(u, f):
    flow[u] = f
    if u:
        c_unknown[par[u]] -= 1
        c_minrem[par[u]] -= minflow[u]
        c_sum[par[u]] += flow[u]
    Q.append(u)
def check(u):
    if flow[u] <= 0 and c_unknown[u] == 0 and children[u]:
        assign(u, c_sum[u])
    if (flow[u] > 0 and c_unknown[u] > 0 and
          (c_unknown[u] == 1 or flow[u] - c_sum[u] == c_minrem[u])):
        for v in children[u]:
            if flow[v] <= 0:
                assign(v, (flow[u] - c_sum[u]) * minflow[v] / c_minrem[u])
                
for u in range(n): check(u)
while Q:
    u = Q.pop()
    check(u)
    if u > 0: check(par[u])

if any(c_unknown[u] or flow[u] <= 0 or children[u] and c_sum[u] != flow[u] for u in range(n)):
    print 'impossible'
else:
    print '\n'.join(map(str, flow))
