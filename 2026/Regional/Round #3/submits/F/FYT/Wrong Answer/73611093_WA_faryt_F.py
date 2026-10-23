n = int(input())
l = []
for i in range(n):
    sen = str(input())
    x = len(sen)
    l.extend(sen)
    for i in range(x):
        z = l.count(l[0])
        if z == x:
            print(0)
            break
    else:
        print((2 * x) - 2)