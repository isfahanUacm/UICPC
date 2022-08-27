n = int(input())
s = ""
for i in range(n):
    s+=input()
    
res = 0
while s.find("O")!=-1:
    s = s[s.find("O"):]
    t = s[s.rfind("O"):]
    s = s[:s.rfind("O")]
    t = t.replace("Z", "O")
    t = t.replace("O", "Z", 1)
    s += t
    res+=1
    
print(res)
    