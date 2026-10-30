t = int(input())
for i in range(t):
    n = int(input())
    a= list(map(int, input().split()))

    if 1 in a:
        if len(set(a)) == 1:
            print(0)
        else:
            print(1)
    else:
        print(2)