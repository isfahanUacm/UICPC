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

for i in range(c):
    for j in range(r):
        if (northern[i] <= eastern[j] and city[j][i] == -1):
            city[j][i] = northern[i];


for i in range(r):
    max_in_row = max(city[i])
    if max_in_row != eastern[i]:
        print("impossible")
        exit(0)

for i in range(c):
    column = []
    for j in range(r):
        column.append(city[j][i])
    
    max_in_clm = max(column)
    if (max_in_clm != northern[i]):
        print("impossible")
        exit(0)

print("possible")