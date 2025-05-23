def find_matching(graph, U, V):
    pair_u = {u: None for u in U}
    pair_v = {v: None for v in V}
    dist = {}

    def bfs():
        queue = []
        for u in U:
            if pair_u[u] is None:
                dist[u] = 0
                queue.append(u)
            else:
                dist[u] = float('inf')
        dist[None] = float('inf')

        while queue:
            u = queue.pop(0)
            if dist[u] < dist[None]:
                for v in graph.get(u, []):
                    matched_u = pair_v[v]
                    if dist.get(matched_u, float('inf')) == float('inf'):
                        dist[matched_u] = dist[u] + 1
                        queue.append(matched_u)
        return dist[None] != float('inf')

    def dfs(u):
        if u is None:
            return True
        for v in graph.get(u, []):
            matched_u = pair_v[v]
            if dist.get(matched_u, float('inf')) == dist[u] + 1:
                if dfs(matched_u):
                    pair_u[u] = v
                    pair_v[v] = u
                    return True
        return False

    matching_size = 0
    while bfs():
        for u in U:
            if pair_u[u] is None:
                if dfs(u):
                    matching_size += 1

    return matching_size


# Input
n = int(input())
s = list(map(int, input().split()))

# Build bipartite graph: U = id0, id1,...; V = integers or their masked versions
graph = {}
U = []
V = set()

for i in range(n):
    u = f"id{i}"
    U.append(u)
    graph[u] = []
    graph[u].append(s[i])
    V.add(s[i])
    for j in range(30):
        if (s[i] >> j) & 1:
            v = s[i] & ~(1 << j)
            graph[u].append(v)
            V.add(v)

# Find maximum matching
matched = find_matching(graph, U, V)
print("Yes" if matched == n else "No")
