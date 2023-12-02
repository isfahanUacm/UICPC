t=int(raw_input())
for tc in range(t):
    a1,b1,a2,b2,a3,b3=map(int,raw_input().split())
    A=[(a1,b1), (a2,b2), (a3,b3)]
    ans = float("inf")
    for i in range(3):
        U,X,Y = A[i],A[(i+1)%3],A[(i+2)%3]
        for k,l in [(0,1), (1,0)]:
            for u,v in [(0,0), (0,1), (1,0), (1,1)]:
                ans = min(ans, max(U[k], X[u], Y[v]) * (U[l] + X[1-u] + Y[1-v]),
                        max(U[k], X[u] + Y[v]) * (U[l] + max(X[1-u], Y[1-v])))
    print ans
