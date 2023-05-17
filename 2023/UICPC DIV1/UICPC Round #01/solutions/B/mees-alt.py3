input()
l = [int(x) if x not in "()" else x for x in input().split()]

s = [0]
o = True
M = 10**9 + 7

for t in l:
    if t == "(":
        o = not o
        s.append(0 if o else 1)
    elif t == ")":
        o = not o
        last = s.pop()
        s[-1] = s[-1]+last if o else s[-1]*last
        s[-1] %= M
    else:
        s[-1] = s[-1]+t if o else s[-1]*t
        s[-1] %= M

print(sum(s) % M)
