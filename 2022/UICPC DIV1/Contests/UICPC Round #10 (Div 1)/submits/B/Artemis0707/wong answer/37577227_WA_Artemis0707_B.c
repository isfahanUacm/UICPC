tc = int(input())

for _ in range(tc):
    a = input()
    b = input()

    a = a.replace("B", "")
    b = b.replace("B", "")

    changing = True
    while changing:
        changing = False
        le = len(a)
        a = a.replace("AA", "")
        a = a.replace("CC", "")
        if le != len(a):
            changing = True

    changing = True
    while changing:
        changing = False
        le = len(b)
        b = b.replace("AA", "")
        b = b.replace("CC", "")
        if le != len(b):
            changing = True

    if a == b:
        print('YES')
    else:
        print('NO')