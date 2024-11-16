T = int(input())
for TT in range(T) :
    n, q = map(int , input().split())
    l = list(map(int, input().split()))
    kk = list(map(int, input().split()))

    for k in kk :
        for i in range(int(k/2)) :
            l.pop(i)
        for i in range(int(k/4)) :
            l[i], l[int(k/2-i-1)] = l[int(k/2-i-1)], l[i]

    for i in l :
        print(i , end = " ")
