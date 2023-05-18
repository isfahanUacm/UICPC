
class dll:
    def __init__(self, datum):
        self.datum = datum
        self.left = None
        self.right = None

    def __str__(self):
        cur = self
        while cur.left is not None:
            cur = cur.left
        result = [cur.datum]
        while cur.right is not None:
            cur = cur.right
            result.append(cur.datum)
        return str(result)


input()
l = ['(', '('] + [int(x) if x not in "()" else x for x in input().split()] + [')', ')']
M = 10**9 + 7

cur = dll(l[0])

for t in l[1:]:
    new = dll(t)
    cur.right = new
    new.left = cur
    cur = new

o = True
while cur.left is not None:
    # print(cur)
    while cur.datum != "(":
        if cur.left is None:
            break
        if cur.datum == ")":
            o = not o
        cur = cur.left
    hold = cur
    cur = cur.right
    if o:
        acc = 0
        while cur.datum != ")":
            acc += cur.datum
            cur = cur.right
    else:
        acc = 1
        while cur.datum != ")":
            acc *= cur.datum
            acc %= M
            cur = cur.right

    new = dll(acc % M)
    new.left = hold.left
    if new.left is not None:
        new.left.right = new
    new.right = cur.right
    if new.right is not None:
        new.right.left = new
    cur = new
    o = not o
    # print(cur.datum)

print(cur.datum % M)
