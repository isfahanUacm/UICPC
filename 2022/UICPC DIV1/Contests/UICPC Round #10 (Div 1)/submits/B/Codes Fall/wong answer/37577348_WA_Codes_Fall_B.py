def change(x):
    y = ""
    while x != y:
        y = x
        x = x.replace("AA", "")
        x = x.replace("CC", "")

    return "".join(x)


t = int(input())

for _ in range(t):
    u = input()
    v = input()

    if u == v:
        print("YES")

    if u.count("B") % 2 == v.count("B") % 2:
        u = u.replace("B", "")
        v = v.replace("B", "")
        u = change(u)
        v = change(v)
    else:
        print("NO")
        continue

    if u == v:
        print("YES")
    else:
        print("NO")
