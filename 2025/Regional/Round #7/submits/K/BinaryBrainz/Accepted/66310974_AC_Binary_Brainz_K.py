n=int(input())
tmp=(n*n+n)
sum=2*tmp
tmp1=tmp*(2*n+1)
sum+=(4*(tmp1))//6
sum+=n
print(sum% 1000000007,end='')