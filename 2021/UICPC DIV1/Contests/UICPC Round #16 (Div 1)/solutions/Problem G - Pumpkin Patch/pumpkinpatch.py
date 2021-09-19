def inrange(i, j, n):
    return 0 <= i < n and 0 <= j < n


dirr = [(0, 1), (1, 0), (-1, 0), (0, -1)]
p, d, n = map(int, input().split())
grid = [['.' for ff in range(n)] for gg in range(n)]
pumpkins = []
for i in range(p):
    y, x = map(int, input().split())
    li = [(y, x) for k in range(4)]
    pumpkins.append([(y, x), 'ALIVE', '-', li.copy()], )
    grid[y][x] = str(i)
for day in range(1, d+1):
    for pi, pumpkin in enumerate(pumpkins):
        if pumpkin[1] == 'dead':
            continue
        for kd in range(4):
            nxt = (pumpkin[3][kd][0] + dirr[kd][0], pumpkin[3][kd][1] + dirr[kd][1])
            if inrange(nxt[0], nxt[1], n):
                if grid[nxt[0]][nxt[1]] != '.':
                    if pumpkins[int(grid[nxt[0]][nxt[1]])][1] == 'ALIVE' and nxt in pumpkins[int(grid[nxt[0]][nxt[1]])][3]:
                        pumpkins[int(grid[nxt[0]][nxt[1]])][1] = 'todie'
                        grid[nxt[0]][nxt[1]] = '.'
                    pumpkin[1] = 'todie'
                    # print(nxt, 'die')
                else:
                    grid[nxt[0]][nxt[1]] = str(pi)
                    pumpkin[3][kd] = nxt
            else:
                pumpkin[1] = 'todie'
                # print(nxt, 'die')
    for pumpkin in pumpkins:
        # print(day, pumpkin)
        if pumpkin[1] == 'todie':
            pumpkin[1] = 'dead'
            pumpkin[2] = day
for pumpkin in pumpkins:
    if pumpkin[1] == 'dead':
        print(pumpkin[2])
    else:
        print(pumpkin[1])

