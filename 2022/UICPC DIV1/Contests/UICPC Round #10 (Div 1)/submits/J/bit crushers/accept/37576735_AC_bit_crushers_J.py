# a,b=[int(num) for num in input().split()]
testcase=int(input())
for _ in range(testcase):
    n,m=[int(num) for num in input().split()]
    # arr=[int(num) for num in input().split()]
    rm,wm=0,0
    for k in range(m):
        r,w=[int(num) for num in input().split()]
        rm=max(rm,r)
        wm=max(wm,w)
    
    if wm+rm>n:
        print("IMPOSSIBLE")
    else:
        print("R"*rm+"W"*wm+"W"*(n-rm-wm))
