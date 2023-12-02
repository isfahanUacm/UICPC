n,m,a = map(int,input().split())

if a % n ==0 or a % m == 0:
    print(1)

else:
    ok = True
    for i in range(1,n+1):
        if a % i ==0 and a // i <= m:
            print(2)
            ok = False
            break
    
    if ok:
        print(3)




