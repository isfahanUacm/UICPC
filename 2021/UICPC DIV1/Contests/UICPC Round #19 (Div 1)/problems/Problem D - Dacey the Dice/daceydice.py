import sys

sys.setrecursionlimit(10 ** 6)

di = {i: {'162543': False, '163425': False, '165234': False, '164352': False, '612534': False, '614325': False, '615243': False, '613452': False, '256143': False, '253461': False, '251634': False, '254316': False, '526134': False, '524361': False, '521643': False, '523416': False, '342516': False, '346125': False, '345261': False, '341652': False, '432561': False, '431625': False, '435216': False, '436152': False} for i in range(400)}


def set_side(state, move):
    if move == 0:
        return state[3] + state[2] + state[0] + state[1] + state[4] + state[5]
    elif move == 1:
        return state[5] + state[4] + state[2] + state[3] + state[0] + state[1]
    elif move == 2:
        return state[4] + state[5] + state[2] + state[3] + state[1] + state[0]
    elif move == 3:
        return state[2] + state[3] + state[1] + state[0] + state[4] + state[5]


def inrange(x, y, n):
    return 0 <= x <= n-1 and 0 <= y <= n-1


def dfs(state, target, li, visited, n):
    x = state[0] // n
    y = state[0] % n
    if x == target[0] and y == target[1] and state[1][1] == '5':
        return True
    ans = False
    visited[state[0]][state[1]] = True
    dirx = [0, -1, 1, 0]
    diry = [1, 0, 0, -1]
    for mm in range(4):
        newst = set_side(state[1], mm)
        if inrange(x + dirx[mm], y + diry[mm], n) and li[x + dirx[mm]][y + diry[mm]] != '*' and not visited[(x + dirx[mm]) * n + (y + diry[mm])][newst]:
            ans = dfs(((x + dirx[mm]) * n + (y + diry[mm]), newst), target, li, visited, n)
            if ans:
                break
    return ans


t = int(input())
for i in range(t):
    n = int(input())
    li = [input() for j in range(n)]
    visited = {i: {'162543': False, '163425': False, '165234': False, '164352': False, '612534': False, '614325': False, '615243': False, '613452': False, '256143': False, '253461': False, '251634': False, '254316': False, '526134': False, '524361': False, '521643': False, '523416': False, '342516': False, '346125': False, '345261': False, '341652': False, '432561': False, '431625': False, '435216': False, '436152': False} for i in range(n*n)}
    st, tr = 0, 0
    for j in range(n):
        for k in range(n):
            if li[j][k] == 'S':
                st = (j*n + k, '162543')
            elif li[j][k] == 'H':
                tr = (j, k)
    ans = dfs(st, tr, li, visited, n)
    print('Yes' if ans else 'No')