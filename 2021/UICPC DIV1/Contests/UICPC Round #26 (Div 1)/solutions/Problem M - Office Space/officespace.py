import sys
lines = sys.stdin.readlines()
n = len(lines)
i = 0
while i != n:
    employees = []
    w, h = map(int, lines[i].split())
    grid = [[0 for k in range(h)] for l in range(w)]
    i += 1
    m = int(lines[i])
    i += 1
    for j in range(i, i+m):
        li = lines[j].split()
        employees.append([li[0], int(li[1]), int(li[2]), int(li[3]), int(li[4]), 0])
        for k in range(int(li[1]), int(li[3])):
            for l in range(int(li[2]), int(li[4])):
                grid[k][l] += 1
    i += m
    total = w*h
    unallocated = 0
    contested = 0
    for j in range(w):
        for k in range(h):
            if not grid[j][k]:
                unallocated += 1
            elif grid[j][k] > 1:
                contested += 1
            else:
                for e in employees:
                    if e[1] <= j < e[3] and e[2] <= k < e[4]:
                        e[5] += 1
                        break
    print('Total', total)
    print('Unallocated', unallocated)
    print('Contested', contested)
    for e in employees:
        print(e[0], e[5])
    if i != n:
        print()