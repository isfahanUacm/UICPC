q = int(input())

while (q):

    n = int(input())
    
    aray = list(map(int, input().split()))

    for i in range(n):
        maximum = max(aray)
        index = aray.index(maximum)
        if maximum > index + 1:
            print("NO")
            break
        else:
            del(aray[index])

    if len(aray) == 0:
        print("YES")

    q -= 1