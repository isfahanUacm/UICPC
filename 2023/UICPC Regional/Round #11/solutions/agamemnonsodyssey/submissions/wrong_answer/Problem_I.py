#!/usr/bin/python3
import collections


def maxResources(N, k, paths):
    result = 0
    if k >= 2:
        for _, _, c in paths:
            result += c
        return result
    graph = collections.defaultdict(list)
    for u, v, c in paths:
        graph[u].append((v, c))
        graph[v].append((u, c))

    def maxPath(indeg, root):
        nonlocal result
        lst = graph[root]
        maxPathSum = 0
        secondMaxPathSum = 0
        for v, c in lst:
            if v == indeg:
                continue
            path = maxPath(root, v) + c
            if path > maxPathSum:
                secondMaxPathSum = maxPathSum
                maxPathSum = path
        result = max(result, secondMaxPathSum + maxPathSum)
        return maxPathSum
    maxPath(0, 1)
    return result


N, k = map(int, input().split())
paths2 = []
for i in range(N - 1):
    paths2.append(map(int, input().split()))


# paths1 = [(1, 2, 3), (2, 3, 1), (1, 4, 5), (1, 5, 9)]
# paths2 = [(1, 2, 3), (2, 3, 1), (1, 4, 5), (1, 5, 9)]
print(maxResources(N, k, paths2))
# print(maxResources(5, 2, paths2))
