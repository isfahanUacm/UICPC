t=int(input())

for _ in range(t):
    u=input() # base
    v=input() # mutated
        
    if len(u)%2 != len(v)%2:
        print("NO")
        continue
    
    for i in range(max(len(u),len(v))):
        if v[i]==u[i]:
            continue
        
        if u[i:i+2] == "AA": v = v[0:i] + "AA" + v[i:]
        elif u[i:i+2] == "BB": v = v[0:i] + "BB" + v[i:]
        elif u[i:i+2] == "CC": v = v[0:i] + "CC" + v[i:]
        elif u[i:i+2] == "AB": v = v[0:i] + "ABAB" + v[i:]
        elif u[i:i+2] == "BC": v = v[0:i] + "BCBC" + v[i:]
        
        elif v[i:i+2] == "AA": v = v[0:i] + v[i+2:]
        elif v[i:i+2] == "BB": v = v[0:i] + v[i+2:]
        elif v[i:i+2] == "CC": v = v[0:i] + v[i+2:]
        elif v[i:i+2] == "AB": v = v[0:i] + v[i+4:]
        elif v[i:i+2] == "BC": v = v[0:i] + v[i+4:]
        

    # print(f"=> {u}")
    # print(f"=> {v}")
    
    if u != v[0:len(u)]:
        print("NO")
        continue
    
    v = v[len(u):]
    for i in ['AA','BB','CC','ABAB','BCBC']:
        v=v.replace(i,'')
    
    if len(v)==0: print('YES')
    else: print('NO')
        