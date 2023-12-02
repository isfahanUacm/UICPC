n,m,a=map(int,raw_input().split())
split=lambda a:any(a%x==0 for x in range(1+a/n,m))
print 1 if a%n==0 or a%m==0 else 2 if split(a) or split(n*m-a) else 3
