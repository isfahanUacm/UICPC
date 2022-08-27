n = int(input())
pile = []
for i in range(n):
    pile.append(input())

pile.reverse()
#print(pile)
it=0
zc = 0
res = 0
while (it<n):
    if pile[it]=='Z':
        zc+=1
        it+=1
    else:
        pile[it]='Z'
        if zc==0:
            res+=1
        elif zc==1:
            res+=2
        else:
            res+=(zc-1)*4
        zc=0
        it=0
print(res)