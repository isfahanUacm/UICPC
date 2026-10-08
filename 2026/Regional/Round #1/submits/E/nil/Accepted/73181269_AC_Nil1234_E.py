n, p = list(map(int, input().split()))

w = []
for _ in range(n):
    t = input().split()
    w.append(t)

s = [0 for _ in range(p)]
t = [0 for _ in range(p)]
f = [0 for _ in range(p)]
for i in range(n):
    for j in range(p):
        s[j] += 1 if w[i][2 * j] == '+' else 0
        t[j] += 0 if w[i][2 * j] == '-' and w[i][2 * j + 1] == '0' else 1
        f[j] += int(w[i][2 * j + 1])



for i in range(p):
    print(s[i], t[i], f[i])