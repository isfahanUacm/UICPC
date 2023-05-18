input()
l = [int(x) if x not in "()" else x for x in input().split()]

s = []
o = True
M = 10**9 + 7

for t in l:
    if t == ")":
        if o:
            acc = 0
            while s[-1] != "(":
                acc += s.pop()
                acc %= M
            s.pop()
            s.append(acc)
            o = False
        else:
            acc = 1
            while s[-1] != "(":
                acc *= s.pop()
                acc %= M
            s.pop()
            s.append(acc)
            o = True
    else:
        if t == "(":
            o = not o
        s.append(t)

print(sum(s) % M)
