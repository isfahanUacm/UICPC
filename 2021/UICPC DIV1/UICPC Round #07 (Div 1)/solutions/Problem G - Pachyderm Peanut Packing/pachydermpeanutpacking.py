while True:
    n = int(input())
    if n == 0:
        break
    basket = []
    for i in range(n):
        x1, y1, x2, y2, siz = map(str, input().split())
        x1, y1, x2, y2 = float(x1), float(y1), float(x2), float(y2)
        basket.append(((x1, y1), (x2, y2), siz))
    m = int(input())
    for i in range(m):
        x, y, siz = map(str, input().split())
        x, y = float(x), float(y)
        flag = True
        for b in basket:
            if b[0][0] <= x <= b[1][0] and b[0][1] <= y <= b[1][1]:
                if b[2] == siz:
                    print(siz, 'correct')
                else:
                    print(siz, b[2])
                flag = False
                break
        if flag:
            print(siz, 'floor')
    print()
