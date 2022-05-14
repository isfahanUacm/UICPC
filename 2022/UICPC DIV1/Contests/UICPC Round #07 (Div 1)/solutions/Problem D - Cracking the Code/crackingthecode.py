t = int(input())
for _ in range(t):
    n = int(input())
    M = [input() for i in range(n)]
    D = input()
    X = input()
    RD = dict()
    candid = []
    for i in range(26):
        li = []
        for j in range(len(D)):
            if D[j] == chr(ord('a') + i):
                li.append(j)
        if len(li) > 1:
            RD[chr(ord('a') + i)] = li
    for i, m in enumerate(M):
        Rm = dict()
        if len(m) != len(D):
            continue
        flag = True
        for v in RD.values():
            ch = m[v[0]]
            for ii in range(len(v)):
                if ch != m[v[ii]]:
                    flag = False
                    break
            if not flag:
                break
        if not flag:
            continue
        
        for i in range(26):
            li = []
            for j in range(len(m)):
                if m[j] == chr(ord('a') + i):
                    li.append(j)
            if len(li) > 1:
                Rm[chr(ord('a') + i)] = li
        
        flag = True
        for v in Rm.values():
            ch = D[v[0]]
            for ii in range(len(v)):
                if ch != D[v[ii]]:
                    flag = False
                    break
            if not flag:
                break
        if not flag:
            continue
        candid.append(m)
    # print(candid)
    if len(candid) == 0:
        print('IMPOSSIBLE')
    elif len(candid) == 1:
        decr = ['?'] * 26
        for i, ch in enumerate(candid[0]):
            decr[ord(ch) - ord('a')] = D[i]
        if decr.count('?') == 1:
            for i in range(26):
                if decr[i] == '?':
                    it = i
                if chr(i + ord('a')) not in decr:
                    ch = chr(i + ord('a'))
            decr[it] = ch
        res = ''
        for ch in X:
            print(decr[ord(ch) - ord('a')], end='')
        print()
    else:
        decr = ['?'] * 26
        intersept = []
        for i in range(26):
            flag = True
            ccs = []
            for c in range(len(candid[0])):
                if candid[0][c] == chr(ord('a') + i):
                    ccs.append(c)
            for j in range(1, len(candid)):
                for c in ccs:
                    if candid[j][c] != chr(ord('a') + i):
                        flag = False
                        break
                if not flag:
                    break
            if flag and ccs:
                decr[i] = D[ccs[0]]
        if decr.count('?') == 1:
            for i in range(26):
                if decr[i] == '?':
                    it = i
                if chr(i + ord('a')) not in decr:
                    ch = chr(i + ord('a'))
            decr[it] = ch
                
        res = ''
        for ch in X:
            print(decr[ord(ch) - ord('a')], end='')
        print()