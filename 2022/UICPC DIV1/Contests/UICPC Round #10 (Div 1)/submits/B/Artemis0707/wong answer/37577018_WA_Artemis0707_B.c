tc = int(input())

for _ in range(tc):
    a = input()
    b = input()

    a = a.replace("B", "")
    b = b.replace("B", "")

    a = a.replace("AA", "")
    a = a.replace("CC", "")

    b = b.replace("AA", "")
    b = b.replace("CC", "")

    if a == b:
        print('YES')
    else:
        print('NO')