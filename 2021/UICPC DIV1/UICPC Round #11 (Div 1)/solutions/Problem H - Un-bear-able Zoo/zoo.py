c = 0
while True:
    n = int(input())
    if not n:
        break
    c += 1
    di = {}
    for i in range(n):
        w = input().split()[-1].lower()
        if w not in di:
            di[w] = 1
        else:
            di[w] += 1
    li = []
    for k in di:
        li.append((k, di[k]))
    li.sort()
    print('List %d:' %c)
    for a in li:
        print(a[0], '|', a[1])
