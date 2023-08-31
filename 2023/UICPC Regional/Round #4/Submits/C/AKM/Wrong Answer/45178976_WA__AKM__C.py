n = int(input())

codes = dict()
for i in range(n):
    
    ls = list()
    name = input()
    while True:
        s = input()
        if(s == "***END***"):
            break
        
        s = s.lstrip()
        s = s.rstrip()  
        s = ' '.join(s.split())
        
        if(len(s) == 0):
            continue
        
        ls.append(s)
    
    codes[name] = ls
    
    
aim = list()
while True:
    s = input()
    if(s == "***END***"):
        break
        
    s = s.lstrip()
    s = s.rstrip()  
    s = ' '.join(s.split())
    aim.append(s)

szA = len(aim)

res = dict()
mx = 0

for name in codes:
    szN = len(codes[name])
    ls = codes[name]
    dp = [[0 for j in range(szA + 1)] for i in range(szN + 1)]
    
    for i in range(szN-1, -1, -1):
        for j in range(szA-1, -1, -1):
            if(ls[i] == aim[j]):
                dp[i][j] = dp[i + 1][j + 1] + 1
                
    value = 0
    for i in range(szN):
        for j in range(szA):
            value = max(value, dp[i][j])
    
    res[name] = value
    mx = max(mx, value)
    
print(mx, end=' ')
for name in res:
    if(res[name] == mx):
        print(name, end = ' ')