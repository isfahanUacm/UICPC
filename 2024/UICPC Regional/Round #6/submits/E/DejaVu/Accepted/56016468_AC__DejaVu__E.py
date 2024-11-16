import math

t = int(input())

for i in range(t):
    a, b = input().split()
    if '.' in a:
        x = a.split('.')
        x = x[0] + x[1]
        for i in range(9 - len(a.split('.')[1])):
            x += '0'
    else:
        x = a
        for i in range(9):
            x += '0'

    if '.' in b:
        y = b.split('.')
        y = y[0] + y[1]
        for i in range(9 - len(b.split('.')[1])):
            y += '0'
    else:
        y = b
        for i in range(9):
            y += '0'

    x = int(x.lstrip('0'))
    y = int(y.lstrip('0'))

    p = int(math.gcd(x, y))
    x = x // p
    y = y // p

    prime = True
    for i in range(2, int(math.sqrt(x) + 2)):
        if x % i == 0 and x > i:
            prime = False
    if x == 1:
        prime = False

    prime2 = True
    for i in range(2, int(math.sqrt(y) + 2)):
        if y % i == 0 and y > i:
            prime = False
    if y == 1:
        prime2 = False

    if x == 1 and y == 1:
        print(2, 2)
    elif prime and prime2:
        print(x, y)
    else:
        print("impossible")
