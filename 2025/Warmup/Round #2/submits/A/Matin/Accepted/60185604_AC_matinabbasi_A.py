for _ in range(int(input())):
    n, c = map(int, input().split())
    a = list(map(int, input().split()))
    d = c
    ans = 1
    for i in a:
        if i >= d:
            ans += 1
            d = c
        else:
            d -= i
    print(ans) 
