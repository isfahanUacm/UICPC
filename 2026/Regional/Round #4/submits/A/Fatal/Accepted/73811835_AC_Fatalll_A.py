t = int(input())

for i in range(t):
    n = int(input())
    a = list(map(int, input().split()))
    counter = 0

    for k in range(n):
        if a[k] > k+1:
            print("NO")
            break
        if(k == n-1):
            print("YES")

