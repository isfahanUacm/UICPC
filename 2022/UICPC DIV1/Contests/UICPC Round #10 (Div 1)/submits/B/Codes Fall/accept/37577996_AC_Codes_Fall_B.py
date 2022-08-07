t = int(input())
for _ in range(t):
    u = input()
    v = input()

    if u.count("B") % 2 == v.count("B") % 2:
        u = u.replace("B", "")
        v = v.replace("B", "")
        for i in range(100):
            u = u.replace("AA", "")
            u = u.replace("CC", "")
            v = v.replace("AA", "")
            v = v.replace("CC", "")
    else:
        print("NO")
        continue

    if u == v:
        print("YES")
    else:
        print("NO")
