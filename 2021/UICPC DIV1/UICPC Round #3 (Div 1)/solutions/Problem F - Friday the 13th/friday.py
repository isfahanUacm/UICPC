T = int(input())
for i in range(T):
    d, m = map(int, input().split())
    di = list(map(int, input().split()))
    cur = 2
    res = 0
    for md in di:
        if md >= 13:
            if not (cur + 12) % 7:
                res += 1
        cur = (cur + md) % 7
    print(res)