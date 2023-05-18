n = int(input())

l = [int(input()) for _ in range(2**n)]

results = []
for step in range(n):
    l.sort()
    cur = l[1] - l[0]
    results.append(cur)

    new_l = []
    seen = {}
    for k in l:
        if k - cur in seen and seen[k-cur] > 0:
            seen[k-cur] -= 1
        else:
            if k not in seen:
                seen[k] = 0
            seen[k] += 1
            new_l.append(k)
    if l[0] != 0 or len(new_l) != len(l)//2 or not all(x == 0 for x in seen.values()):
        print("impossible")
        break
    l = new_l
else:
    print("\n".join(str(x) for x in results))
