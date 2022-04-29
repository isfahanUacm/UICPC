def reachable(t1, t2, r):
    return ((t1[0] - t2[0]) ** 2 + (t1[1] - t2[1]) ** 2) <= r * r

l, w, n, r = map(int, input().split())
cranes = [tuple(map(int, input().split())) for i in range(n)]
feasible = [False] * 16
centers = [
    (-l / 2, 0), (l / 2, 0), (0, -w / 2), (0, w / 2)
]
for mask in range(1, 16):
    for crane in cranes:
        flag = True
        for i in range(4):
            if mask & 1 << i and not reachable(centers[i], crane, r):
                flag = False
                break
        if flag:
            feasible[mask] = True
            break
if feasible[15]:
    print(1)
    exit(0)
for i in range(1, 15):
    if feasible[i] and feasible[15-i]:
        print(2)
        exit(0)
for i in range(4):
    for j in range(4):
        if i == j:
            continue
        if feasible[1 << i] and feasible[1 << j] and feasible[15 - (1 << i) - (1 << j)]:
            print(3)
            exit(0)
print(4 if feasible[1] and feasible[2] and feasible[4] and feasible[8] else 'Impossible')