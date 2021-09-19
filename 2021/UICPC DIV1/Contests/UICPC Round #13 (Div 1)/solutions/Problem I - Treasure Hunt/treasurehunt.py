r, c = map(int, input().split())
grid = []
for i in range(r):
    grid.append(input())
cur = (0, 0)
cnt = 0
while True:
    if grid[cur[0]][cur[1]] == 'T':
        print(cnt)
        break
    elif grid[cur[0]][cur[1]] == 'N':
        if 0 <= cur[0]-1 < r and 0 <= cur[1] < c:
            cur = (cur[0]-1, cur[1])
        else:
            print('Out')
            break
    elif grid[cur[0]][cur[1]] == 'S':
        if 0 <= cur[0] + 1 < r and 0 <= cur[1] < c:
            cur = (cur[0] + 1, cur[1])
        else:
            print('Out')
            break
    elif grid[cur[0]][cur[1]] == 'E':
        if 0 <= cur[0] < r and 0 <= cur[1] + 1 < c:
            cur = (cur[0], cur[1] + 1)
        else:
            print('Out')
            break
    else:
        if 0 <= cur[0] < r and 0 <= cur[1] - 1 < c:
            cur = (cur[0], cur[1] - 1)
        else:
            print('Out')
            break
    cnt += 1
    if cnt > r*c+10:
        print('Lost')
        break
