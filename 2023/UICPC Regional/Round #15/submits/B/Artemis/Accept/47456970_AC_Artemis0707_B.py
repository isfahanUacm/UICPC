rythem = len(list(input().split()))
n = int(input())
names = []
for i in range(n):
    names.append(input())

team1 = []
team2 = []

i = 0
name_indx = 0
while len(names) > 0:
    name_indx = (name_indx + rythem - 1) % len(names)
    if i % 2 == 0:
        team1.append(names[name_indx])
        names.pop(name_indx)
    else:
        team2.append(names[name_indx])
        names.pop(name_indx)
    i += 1
    

print(len(team1))
for name in team1:
    print(name)
print(len(team2))
for name in team2:
    print(name)
    
    
