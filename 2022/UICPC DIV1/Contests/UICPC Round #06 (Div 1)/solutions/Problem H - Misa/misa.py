def inrange(i, j, R, C):
    return 0 <= i < R and 0 <= j < C

directions = [
    (1, 0), (1, 1), (0, 1), (-1, 1), (-1, 0), (-1, -1), (0, -1), (1, -1)
]
directions2 = [
    (1, 0), (0, 1), (1, 1), (1, -1)
]
r, s = map(int, input().split())
seat = [[] for i in range(r)]
empties = []
for i in range(r):
    row = input()
    for j in range(s):
        seat[i].append(row[j])
        if row[j] == '.':
            empties.append((i, j))
mx_i, mx = -1, -1
for empty in empties:
    c = 0
    for d in directions:
        if inrange(empty[0] + d[0], empty[1] + d[1], r, s) and seat[empty[0] + d[0]][empty[1] + d[1]] == 'o':
            c += 1
    if c > mx:
        mx = c
        mx_i = empty
if mx != -1:
    seat[mx_i[0]][mx_i[1]] = 'o'
res = 0
for i in range(r):
    for j in range(s):
        if seat[i][j] == 'o':
            for d in directions2:
                if inrange(i + d[0], j + d[1], r, s) and seat[i + d[0]][j + d[1]] == 'o':
                    res += 1
print(res)
