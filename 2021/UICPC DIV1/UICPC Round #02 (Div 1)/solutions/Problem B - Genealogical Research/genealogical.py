anc = {}
dec = {}
li = []
mp = {}


def ancestors(_id, rec):
    if rec:
        print(' ' * (rec * 2), end='')
        print(li[_id][0], li[_id][1], '-', end='')
        if li[_id][2] is not None:
            print(' '+li[_id][2])
        else:
            print()
    lis = sorted([li[_id][3], li[_id][4]])
    if _id not in anc:
        print(' ' * ((rec+1) * 2) + lis[0])
        print(' ' * ((rec+1) * 2) + lis[1])
    elif len(anc[_id]) == 2:
        ancestors(mp[lis[0]], rec+1)
        ancestors(mp[lis[1]], rec+1)
    else:
        if li[anc[_id][0]][0] == lis[0]:
            ancestors(mp[lis[0]], rec+1)
            print(' ' * ((rec + 1) * 2) + lis[1])
        else:
            print(' ' * ((rec + 1) * 2) + lis[0])
            ancestors(mp[lis[1]], rec + 1)


def decendants(_id, rec):
    if rec:
        print(' ' * (rec * 2), end='')
        print(li[_id][0], li[_id][1], '-', end='')
        if li[_id][2] is not None:
            print(' ' + li[_id][2])
        else:
            print()
    if _id in dec:
        lis = sorted([li[i][0] for i in dec[_id]])
        for child in lis:
            decendants(mp[child], rec + 1)


q = 0
while True:
    s = input()
    if s == 'QUIT':
        break
    if s.startswith('BIRTH'):
        ins = s[6:].split(' : ')
        mid = len(li)
        mp[ins[0]] = mid
        li.append((ins[0], ins[1], None, ins[2], ins[3]))
        if ins[2] in mp and ins[3] in mp:
            idm, idf = mp[ins[2]], mp[ins[3]]
            anc[mid] = [idm, idf]
            if idm not in dec:
                dec[idm] = []
            if idf not in dec:
                dec[idf] = []
            dec[idm].append(mid)
            dec[idf].append(mid)
        elif ins[2] in mp:
            idm = mp[ins[2]]
            anc[mid] = [idm]
            if idm not in dec:
                dec[idm] = []
            dec[idm].append(mid)
        elif ins[3] in mp:
            idf = mp[ins[3]]
            anc[mid] = [idf]
            if idf not in dec:
                dec[idf] = []
            dec[idf].append(mid)
    elif s.startswith('DEATH'):
        ins = s[6:].split(' : ')
        mid = mp[ins[0]]
        li[mid] = (li[mid][0], li[mid][1], ins[1], li[mid][3], li[mid][4])
    elif s.startswith('ANCESTORS'):
        if q:
            print()
        q += 1
        ins = s[10:]
        mid = mp[ins]
        print('ANCESTORS of', li[mid][0])
        ancestors(mid, 0)
    else:
        if q:
            print()
        q += 1
        ins = s[12:]
        mid = mp[ins]
        print('DESCENDANTS of', li[mid][0])
        decendants(mid, 0)
