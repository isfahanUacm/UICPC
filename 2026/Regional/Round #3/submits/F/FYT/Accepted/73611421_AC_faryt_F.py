n = int(input())
for i in range(n):
    sen = str(input())
    x = len(sen)
    l = []
    l.extend(sen)
    z = l.count(l[0])
    if z == x:
        print(0)
    else:
        print((2 * x) - 2)