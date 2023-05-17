r, c = input().split()

r = int(r)
c = int(c)

eastern = input().split();
eastern = [int(x) for x in eastern];

northern = input().split();
northern = [int(x) for x in northern];

city = []
for i in range(r):
    city.append([])
    for j in range(c):
        if (eastern[i] <= northern[j]):
            city[i].append(eastern[i])
        else:
            city[i].append(-1)

possible = True
for i in range(r):
    found = False
    for j in range(c):
        if (city[i][j] != -1):
            found = True
            break
    if (not found):
        possible = False
        break

if (not possible):
    print("impossible")
    exit(0)

for i in range(c):
    found = False
    for j in range(r):
        if (city[j][i] != -1):
            found = True
            break
    if (not found):
        possible = False
        break

if (not possible):
    print("impossible")
else:
    print("possible")
