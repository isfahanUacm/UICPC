for _ in range(int(input())):
    n = int(input())
    a = list(map(int, input().split()))
    f = min(a)
    s = max(a)
    print((s-f)*2)