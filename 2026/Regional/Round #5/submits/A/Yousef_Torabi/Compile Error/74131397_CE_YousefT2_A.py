n,m = map(int,input().split())


a= list(map(int, input().split()))

list = []

for i in range(m,0,-1):
    counter = 0
    for j in range(0,n):
        if i == a[j]:
            counter += 1
    l = len(list)
    if l == 0:
        list.append(counter*i)
    else:
        list.append(list[l-1] + counter*i)

for i in range(m,0,-1):
    print(list[i-1], end=" ")