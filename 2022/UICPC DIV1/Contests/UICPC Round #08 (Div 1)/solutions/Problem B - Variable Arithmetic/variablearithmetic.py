s = input()
d = dict()

while s != '0':
    sm = 0
    if s.find('=') == -1:
        a = s.split(' + ')
        for i in a:
            if i.isdigit():
                sm += int(i)
            else:
                if i in d:
                    sm += d[i]
        if sm != 0:
            print(sm, end='')
        ss = ""
        for i in a:
            if not i.isnumeric() and i not in d:
                ss = ss + ' + ' + i
        if sm == 0:
            ss = ss[3:]
        print(ss, end='')
        print()
    else:
        a = s.split(' = ')
        d[a[0]] = int(a[1])
    s = input()
