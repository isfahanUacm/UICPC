# a,b=[int(num) for num in input().split()]
testcase=int(input())
for _ in range(testcase):
    seen=set()
    dic={i:0 for i in range(1,11)}
    n=int(input())
    for k in range(n):
        b,a=[int(num) for num in input().split()]
        seen.add(a)
        dic[a]=max(dic[a],b)
    if len(seen)<10:print("MOREPROBLEMS")
    else:
        ans=sum([j for i,j in dic.items()])
        print(ans)