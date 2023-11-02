n = int(input())
a = []

for _ in range(n):
    a.append(list(map(int, input().split())))
    a[-1].append(sum(a[-1]))
#print(a)
a.sort(key=lambda x: x[-1], reverse=True)
##print(a)
team_1 = 0
team_2 = 0

for i in range(n//2):
    #print(a[i][-1])
    team_1 += a[i][-1]

for i in range(n//2, n):
    #print(a[i][-1])
    team_2 += a[i][-1]

print((team_1 - team_2)//2)