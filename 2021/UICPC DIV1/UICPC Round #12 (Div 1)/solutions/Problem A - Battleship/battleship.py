t = int(input())
for i in range(t):
    w, h, n = map(int, input().split())
    pg = [[], []]
    sh = [0, 0]
    for j in range(h):
        pg[0].append(input())
        sh[0] += pg[0][j].count('#')
    pg[0].reverse()
    for j in range(h):
        pg[1].append(input())
        sh[1] += pg[1][j].count('#')
    pg[1].reverse()
    turn = 1
    fl = False
    for k in range(n):
        c, r = map(int, input().split())
        if fl and turn:
            continue
        if pg[turn][r][c] == '#':
            pg[turn][r] = pg[turn][r][0:c] + '_' + pg[turn][r][c+1:]
            sh[turn] -= 1
            if not sh[turn]:
                turn = 0 if turn else 1
                fl = True
        else:
            turn = 0 if turn else 1
    if sh[0] == sh[1] == 0 or (sh[0] != 0 and sh[1] != 0):
        print('draw')
    else:
        print('player two wins' if not sh[0] else 'player one wins')

