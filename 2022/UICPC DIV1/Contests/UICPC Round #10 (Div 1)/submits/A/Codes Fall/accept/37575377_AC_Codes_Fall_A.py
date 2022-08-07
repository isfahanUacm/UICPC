t = int(input())

for i in range(t):
    n = int(input())
    point = [0,0,0,0,0,0,0,0,0,0]

    for j in range(n):
        beauty, diff = list(map(lambda x: int(x), input().split()))
        if beauty > point[diff-1]:
            point[diff-1] = beauty

    if all(point):
        print(sum(point))
    else:
        print("MOREPROBLEMS")
