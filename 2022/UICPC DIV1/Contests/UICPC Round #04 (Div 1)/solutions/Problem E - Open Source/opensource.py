di = dict()
li = []
curr = ''
while True:
    inp = input()
    if inp == '0':
        break
    if inp == '1':
        res = []
        for a in di:
            res.append((-len(di[a]), a))
        res.sort()
        for n, a in res:
            print(a, -n)
        di.clear()
        li.clear()
        curr = ''
        continue
    elif ord(inp[0]) < 97:
        if curr != '' and len(di[curr]):
            li.extend(list(di[curr]))
        curr = inp
        di[inp] = set()
    else:
        if inp in li:
            for k in di:
                if inp in di[k]:
                    di[k].remove(inp)
        else:
            di[curr].add(inp)
