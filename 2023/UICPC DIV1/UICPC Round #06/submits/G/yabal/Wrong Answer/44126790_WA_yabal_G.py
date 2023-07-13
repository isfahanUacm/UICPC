firstline = input().split()

n = int(firstline[0])
s = int(firstline[1])

safeHouses = []

for i in range(s):
    safeHouses.append(int(input()))

safety = 0

for i in range(1,n+1):
    if i in safeHouses:
        add = True
    else:
        add = False

    housesOnTheWay = 0
    for j in range(i+1,n+1):
        if add:
            safety += 1
        if j in safeHouses:
            housesOnTheWay += 1
        safety += housesOnTheWay


print(safety)