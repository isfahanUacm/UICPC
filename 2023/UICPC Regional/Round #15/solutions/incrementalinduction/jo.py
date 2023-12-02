I=raw_input
R=range
n=int(I())
d=[0]*n
for i in R(1,n):
 for j,c in enumerate(I()):d[i if c=='1' else j]+=1
O=sorted(R(n),key=lambda i:d[i])
m=c=0
for i in R(n):c+=d[O[i]]-i;m=max(m,c)
print m
