n,s = map(int, input().split())

a = {}
for _ in range(n):
    name, b =  input().split()
    b = int(b)
    a[name] = b

a = sorted(a.items(), key = lambda x: x[1], reverse = True)

ans = 0
ans_name = []

for i in a:
    if i[1] + ans <= s:
        ans += i[1]
        ans_name.append(i[0])
    
if ans != s:
    print(0)
    exit()

print(len(ans_name))
for i in ans_name:
    print(i)