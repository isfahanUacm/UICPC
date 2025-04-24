n, m = map(int, input().split())

expr = input()
expr = expr.replace('-', '+')
expr = expr.replace(' ', '')
expr = expr.split('+')
for i in range(len(expr)):
    expr[i] = expr[i].split('*')

ps = [len(expr[0])]

for i in range(1, len(expr)):
    ps.append(ps[-1] + len(expr[i]))

for i in range(len(expr)):
    for j in range(len(expr[i])):
        expr[i][j] = int(expr[i][j])

even = [0 for i in range(len(expr))]

res = 0

for i in range(len(expr)):
    flag = False
    for j in expr[i]:
        if j % 2 == 0:
            even[i] += 1
            flag = True

    if not flag:
        res += 1

res %= 2

if res == 1:
    print('odd')
else:
    print('even')

for T in range(m):
    u, v = map(int, input().split())
    l, r, ans = 0, len(expr) - 1, len(expr) - 1
    while l <= r:
        mid = (l + r) // 2
        if ps[mid] >= u:
            ans = min(ans, mid)
            r = mid - 1
        else:
            l = mid + 1

    lst = even[ans]

    if ans > 0:
        idx = u - ps[ans - 1] - 1
    else:
        idx = u - 1

    if expr[ans][idx] % 2 == 0:
        even[ans] -= 1
    
    if v % 2 == 0:
        even[ans] += 1

    if lst == 0 and even[ans] > 0:
        res = 1 - res
    elif even[ans] == 0 and lst > 0:
        res = 1 - res

    expr[ans][idx] = int(v)

    if res == 1:
        print('odd')
    else:
        print('even')