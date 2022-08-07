t=int(input())

for _ in range(t):
    u=input()
    v=input()
    
    for i in ['AA','BB','CC','ABAB','BCBC']:
        u=u.replace(i,'')
        v=v.replace(i,'')
            
    if u==v:
        print('YES')
    else:
        print('NO')
        