def find_matching(graph, U, V):
    matching = {}
    dist = {}

    def bfs():
        queue = []
        for u in U:
            if u not in matching:
                dist[u] = 0
                queue.append(u)
            else:
                dist[u] = float('inf')
        dist[None] = float('inf')

        while queue:
            u = queue.pop(0)
            if dist[u] < dist[None]:
                for v in graph.get(u, []):
                    m = matching.get(v)
                    if dist.get(m, float('inf')) == float('inf'):
                        dist[m] = dist[u] + 1
                        queue.append(m)
        return dist[None] != float('inf')

    def dfs(u):
        if u is None:
            return True
        for v in graph.get(u, []):
            m = matching.get(v)
            if dist.get(m, float('inf')) == dist[u] + 1:
                if dfs(m):
                    matching[u] = v
                    matching[v] = u
                    return True
        return False

    while bfs():
        for u in U:
            if u not in matching:
                dfs(u)

    return matching

# Input
n = int(input())
s = list(map(int, input().split()))

# Build bipartite graph: left side = idX, right side = bit-masked integers
graph = {}
U = []
V = set()

for i in range(n):
    u = f"id{i}"
    U.append(u)
    graph[u] = []
    graph[u].append(s[i])
    for j in range(30):
        if (s[i] >> j) & 1:
            v = s[i] & ~(1 << j)
            graph[u].append(v)
            V.add(v)

matching = find_matching(graph, U, V)
if (len(matching) // 2) == n:
    print("Yes")
else:
    print('No')