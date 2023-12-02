M=sum(c==' ' for c in raw_input())
n=int(raw_input())
A=[raw_input() for _ in range(n)]
o=0
T=[[],[]]
for i in range(len(A)):
    i=i%2
    k=(o+M)%len(A)
    T[i] += [A[k]]
    del A[k]
    o = k
for i in [0,1]:
    print len(T[i])
    for a in T[i]:
        print a
