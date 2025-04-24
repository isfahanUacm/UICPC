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
odd = [0 for i in range(len(expr))]

res = 0

for i in range(len(expr)):
    flag = False
    for j in expr[i]:
        if j % 2 == 0:
            even[i] += 1
            flag = True
        else: 
            odd[i] += 1
    if not flag:
        res += 1

res %= 2
print('odd' if res == 1 else 'even')

for T in range(m):
    u, v = map(int, input().split())
    l, r, ans = 0, len(expr), len(expr)
    while l <= r:
        mid = (l + r) // 2
        if ps[mid] >= u:
            ans = min(ans, mid)
            r = mid - 1
        else:
            l = mid + 1

    lst = even[ans]

    idx = ps[ans] - u - 1
    if expr[ans][idx] % 2 == 1:
        odd[ans] -= 1
    else:
        even[ans] -= 1
    
    if v % 2 == 1:
        odd[ans] += 1
    else:
        even[ans] += 1

    lst1 = even[ans]

    if (lst1 == 0 and lst > 0) or (lst == 0 and lst1 > 0):
        res = 1 - res

    print('odd' if res == 1 else 'even')