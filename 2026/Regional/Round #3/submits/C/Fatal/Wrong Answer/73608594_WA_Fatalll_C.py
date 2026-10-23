t = int(input())
for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    counter = 0
    maxCounter = 0
    for j in range(len(a)-1):
        if((a[j+1] - a[j] == 0 or a[j+1] - a[j] == 1) and j != len(a)-1):
            counter += 1
        else:
            if(counter > maxCounter):
                maxCounter = counter
            counter = 0


    print(n - (maxCounter+1))




