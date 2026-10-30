t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    b = []
    b.append(a[0])
    counter = 0
    for i in range(1, n):
        if a[i] not in b:
            b.append(a[i])

        if a[i] != a[i-1]:
            counter += 1
    if len(b) == 1 and 1 in b:
        print(0)
    elif 1 in b and len(b)<3 and counter < 3:
        if a[0] == 1 and len(b)<2:
            print(1)
        else:
            print(2)
    elif len(b) == 1:
        print(1)
    else:
        print(2)