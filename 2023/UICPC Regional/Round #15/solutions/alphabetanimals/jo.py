A = raw_input().strip()
n = int(raw_input())
F = {}
names=[raw_input().strip() for _ in range(n)]
for nm in names:
    F[nm[0]] = 1 + F.get(nm[0], 0)
if not A[-1] in F:
    print "?"
else:
    F[A[-1]] -= 1
    succ = filter(lambda x: x[0] == A[-1], names)
    ans = succ[0]
    for nm in succ:
        if F.get(nm[-1], 0) == 0:
            ans = "%s!" % nm
            break
    print ans
