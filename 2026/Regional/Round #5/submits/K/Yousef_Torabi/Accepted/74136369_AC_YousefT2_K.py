n , q = map(int, input().split())

araye = list(map(int, input().split()))





for i in range(q):
    a = list(map(int, input().split()))
    halat = int(a[0])
    lena = len(a)
    l = a[1]
    r = a[2]
    if lena == 4:
        x = a[3]

    if halat == 1:
        for j in range(l-1,r):
            araye[j] = araye[j] % a[3]
    elif halat == 2:
        for j in range(l-1,r):
            if a[3] > araye[j]:
                araye[j] = a[3]
    elif halat == 3:
        sum = 0
        for j in range(l-1,r):
            sum += int(araye[j])
        print(sum)