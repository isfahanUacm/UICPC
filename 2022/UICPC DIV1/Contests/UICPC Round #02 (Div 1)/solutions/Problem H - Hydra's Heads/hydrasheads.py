while True:
    res = 0
    h, t = map(int, input().split())
    if not (h or t):
        break
    if not t:
        if h % 2:
            print(-1)
            continue
        else:
            print(h // 2)
            continue
    if h % 2:
        if t % 2:
            if not (t+1) % 4:
                res += 3
                t += 3
            else:
                res += 1
                t += 1
        else:
            if not t % 4:
                res += 2
                t += 2
    else:
        if t % 2:
            if (t+1) % 4:
                res += 3
                t += 3
            else:
                res += 1
                t += 1
        else:
            if t % 4:
                res += 2
                t += 2
    res += (h + t // 2)//2 + t // 2
    print(res)
