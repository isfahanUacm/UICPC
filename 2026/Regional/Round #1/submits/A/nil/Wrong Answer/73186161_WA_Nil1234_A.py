def penalty(completed, m, f):
    res = 0
    for i, mi, fi in zip(list(range(len(m))), m, f):
        if not completed[i]:
            continue
        res += mi + 20 * fi
    return res


class sx:
    def __init__(self, l):
        self.s = l[0]
        self.x = l[1]
        self.id = l[2]

    def __lt__(self, other):
        if self.x != other.x:
            return self.s < other.s
        if self.x != other.x:
            return self.x > other.x
        return self.id > other.id

    def __eq__(self, other):
        return self.x == other.x and self.s == other.s

    def __str__(self):
        return f"{self.id} {self.s} {self.x}"


n, p = list(map(int, input().split()))
q = int(input())

f = [[0 for _ in range(p)] for _ in range(n)]
s = [0 for _ in range(n)]
x = [0 for _ in range(n)]
m = [[0 for _ in range(p)] for _ in range(n)]
completed = [[False for _ in range(p)] for _ in range(n)]
for _ in range(q):
    mi, id, t, v = list(map(int, input().split()))
    i = id - 1
    s[i] += v
    if v == 1:
        completed[i][t - 1] = True
        m[i][t - 1] = mi
    if not completed[i][t - 1]:
        f[i][t - 1] += 1
        m[i][t - 1] = mi

for i in range(n):
    x[i] += penalty(completed[i], m[i], f[i])

teams = list(map(sx, zip(s, x, list(range(1, n + 1)))))
teams.sort(reverse=True)

r = 1
same_count = 1
for i in range(n):
    try:
        if teams[i] == teams[i + 1]:
            print(r, teams[i])
            same_count += 1
        else:
            print(r, teams[i])
            r += same_count
            same_count = 1
    except IndexError:
        print(r, teams[i])