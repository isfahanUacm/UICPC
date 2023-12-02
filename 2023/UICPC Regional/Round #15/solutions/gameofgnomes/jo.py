n,m,k=map(int,raw_input().split())
a=0
for r in range(n%k,min(n+1,m*k),k):
  v=r%m;a=max(a,((n-r)/k+1)*(n+r)-2*r+(r/m)*m*(m+1)+v*v+v)
print a/2
