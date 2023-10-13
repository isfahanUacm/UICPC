t = int(input())

for k in range(t):
    inp = input()
    n, q = int(inp.split(' ')[0]), int(inp.split(' ')[1])

    s = str()
    for i in range(n):
        s += '-'

    star = [[] for i in range(n)]

    valid = True

    for i in range(q):
        inp = input()

        id = int(inp.split(' ')[0])
        id -= 1
        p = inp.split(' ')[1]

        if not valid:
            continue

        for j in range(len(p)):
            if p[j] == '*':
                if j == len(p) - 1:
                    break
                
                sstr = p[j + 1:]
                star[id + j].append(sstr)
                break
                
            if p[j] == '.':
                break
            
            if s[id + j] == '-':
                s = s[:id + j] + p[j] + s[id + j + 1 :]
            elif s[id + j] != p[j]:
                valid = False 
                break
            

    for i in range(n):
        for st in star[i]:
            tmp = s[i : ]
            if st not in tmp:
                valid = False
                break
            

    if '-' in s:
        valid = False

    if valid:
        print(s)
    else:
        print('IMPOSSIBLE')        
