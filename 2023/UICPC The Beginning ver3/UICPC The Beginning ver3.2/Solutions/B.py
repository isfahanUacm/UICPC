n = int(input())
s = ""
for i in range(n):
    s+=input()
    
res = 0

for i in range(n):
    if s[i]=='O': res += pow(2,n-i-1)
     
print(res)