
n = int(input())

ls = []
for i in range(n):
    s = input().split(' ')
    if(s[0].isnumeric()): 
        ls.append((int(s[0]) / 2, s[1]))
    else:
        ls.append((int(s[1]), s[0]))

ls = sorted(ls)

for st in ls:
    print(st[1])