xs = []
ys = []


def change(x, i):
    while len(x) >= i+2:
        y = x.copy()
        if x[i]+x[i+1] in ["AA", "BB", "CC"]:
            x.pop(i)
            x.pop(i)
            change(y, i+1)
        elif len(x) >= i + 4 and "".join(x[i:i+4]) in ["ABAB", "BCBC"]:
            x.pop(i)
            x.pop(i)
            x.pop(i)
            x.pop(i)
            change(y, i + 1)
        else:
            i += 1

    xs.append("".join(x))


def change2(x, i):
    while len(x) >= i + 2:
        y = x.copy()
        if x[i] + x[i + 1] in ["AA", "BB", "CC"]:
            x.pop(i)
            x.pop(i)
            change2(y, i + 1)
        elif len(x) >= i + 4 and "".join(x[i:i+4]) in ["ABAB", "BCBC"]:
            x.pop(i)
            x.pop(i)
            x.pop(i)
            x.pop(i)
            change2(y, i + 1)
        else:
            i += 1

    ys.append("".join(x))


t = int(input())

for _ in range(t):
    u = input()
    v = input()
    xs.clear()
    ys.clear()

    if u == v:
        print("YES")

    else:
        change(list(u), 0)
        change2(list(v), 0)
        yes = 0

        for i in xs:
            if yes == 1: break
            for j in ys:
                if yes == 1: break
                if i == j:
                    print("YES")
                    yes = 1

        if yes:
            continue

        print("NO")

