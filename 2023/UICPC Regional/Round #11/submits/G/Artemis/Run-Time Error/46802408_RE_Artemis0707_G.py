import sys

mp = {}
while True:
    s = sys.stdin.readline()
    if s == "\n" or s == '':
        break
    
    s = s.replace(' ', '')
    s = s.replace('\n', '')
    ls = s.split(')')
    
    for val in ls:
        if len(val) == 0 or val == '' or val == '\n':
            continue
        
        val = val.split('(')
        if val[0] not in mp:
            mp[val[0]] = []
            
        args = val[1].split(',')
        mp[val[0]].append(args)

while True:
    s = sys.stdin.readline()
    if s == "\n" or s == '':
        break
    
    s = s.replace(' ', '')
    s = s.replace('\n', '')

    s = s.split('(')
    
    name = s[0]
    args = s[1][0:-1].split(',')
    
    lsArgs = mp[name]
    res = 0
    for argst in lsArgs:
        if len(argst) != len(args):
            continue
        
        mp_t = {}
        ft = True
        for i in range(len(args)):
            flag = False
            if args[i] == '_':
                flag = True
            elif args[i][0] == '_':
                if args[i] not in mp_t:
                    flag = True
                    mp_t[args[i]] = argst[i]
                else:
                    if argst[i] == mp_t[args[i]]:
                        flag = True
            else:
                if(args[i] == argst[i]):
                    flag = True
            
            if not flag:
                ft = False
                break
        
        if ft:
            res += 1
                    
    print(res)
                
        
