n,m,a = map(int,input().split())

if a % n ==0 or a % m == 0:
    print(1)

else:
    for i in range(1,n+1):
        if a % i ==0 and a // i <= m:
            print(2)
            exit()
    for i in range(1,m+1):
        if a % i ==0 and a // i <= n:
            print(2)
            exit()
    
    print(3)

