n = int(raw_input())
parent = [-1] + map(lambda x: int(x) - 1, raw_input().split(' '))
flow = map(lambda x: int(x), raw_input().split(' '))
org_flow = flow[:]
children = [[] for _ in range(n)]
min_flow = [0] * n

for i in xrange(1, n):
    children[parent[i]].append(i)

# Bottom up
for node in xrange(n-1, -1, -1):
    if children[node] and all(flow[c] for c in children[node]):
        flow[node] = sum(flow[c] for c in children[node])
    min_flow[node] = max(1, flow[node], sum(min_flow[c] for c in children[node]))

# Top down
for node in xrange(n):
    left = flow[node] - sum(min_flow[c] for c in children[node])
    if left > 0 and sum(not flow[c] for c in children[node]) >= 2:
        flow[node] = 0  # Ambiguous case
    for c in children[node]:
        if flow[c] == 0:
            flow[c] = min_flow[c] + left


for i in xrange(n):
    if (org_flow[i] > 0 and org_flow[i] != flow[i]) or flow[i] < 1:
        print 'impossible'
        exit(0)

print ' '.join(map(str, flow))
