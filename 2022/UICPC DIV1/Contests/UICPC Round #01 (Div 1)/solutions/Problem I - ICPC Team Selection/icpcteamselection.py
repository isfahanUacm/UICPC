t = int(input())
for i in range(t):
    n = int(input())

    li = list(map(int, input().split()))
    li.sort(reverse= True)
    res = 0
    for j in range(n):
        res += li[2*j+1]
    print(res)
