t = int(input())

while t > 0:
    
    a1, b1, a2, b2, a3, b3 = map(int, input().split())
    res = 1e18        

    for i in range(2):
        for j in range(2):
            for k in range(2):
                
                res = min(res, (a1 + a2 + a3) * max(b1, b2, b3))
                
                if b1 <= b2:
                    res = min(res, max(a1 + a2, a3) * (b2 + b3))
                    res = min(res, (a2 + max(a1, a3)) * max(b2, b1 + b3))
        
                else:   
                    a1, a2 = a2, a1
                    b1, b2 = b2, b1
                    
                    res = min(res, max(a1 + a2, a3) * (b2 + b3))
                    res = min(res, (a2 + max(a1, a3)) * max(b2, b1 + b3))
                    
                    a1, a2 = a2, a1
                    b1, b2 = b2, b1

                if b1 <= b3:
                    res = min(res, max(a1 + a3, a2) * (b3 + b2))
                    res = min(res, (a3 + max(a1, a2)) * max(b3, b1 + b2))
        
                else:   
                    a1, a3 = a3, a1
                    b1, b3 = b3, b1
                    
                    res = min(res, max(a1 + a3, a2) * (b3 + b2))
                    res = min(res, (a3 + max(a1, a2)) * max(b3, b1 + b2))
                    
                    a1, a3 = a3, a1
                    b1, b3 = b3, b1
                
                if b3 <= b2:
                    res = min(res, max(a3 + a2, a1) * (b2 + b1))
                    res = min(res, (a2 + max(a3, a1)) * max(b2, b3 + b1))
        
                else:   
                    a2, a3 = a3, a2
                    b2, b3 = b3, b2
                    
                    res = min(res, max(a3 + a2, a1) * (b2 + b1))
                    res = min(res, (a2 + max(a3, a1)) * max(b2, b3 + b1))
                    
                    a2, a3 = a3, a2
                    b2, b3 = b3, b2

                a3, b3 = b3, a3
            
            a2, b2 = b2, a2
        
        a1, b1 = b1, a1
                
    print(res)
    
    t -= 1