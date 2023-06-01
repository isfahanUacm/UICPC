

D, S = map(int,input().split(' '))

droplets = []

for i in range(D):
    x, y = map( int, input().split(' '))
    droplets.append([x, y, i])

sensors = []

for i in range(S):
    x1, x2, y = map(int, input().split(' '))
    sensors.append([x1, x2, y])

sensors.sort(key= lambda s: s[2], reverse=True)

def dist(sensor):
    results = []
    for droplet in droplets:
       if droplet == None:
           continue
       if (sensor[0] <= droplet[0] <= sensor[1]) and droplet[1] > sensor[2]:
           results.append((droplet[1] - sensor[2], droplet[2]))

    minimum = min(results, key= lambda x: x[0])
    return [i for i in results if i[0] == minimum[0]]


deletedDroplets = []
for (i, sensor) in enumerate(sensors):
    result = dist(sensor)
    for droplet in result:
        newDroplet = droplets[droplet[1]]
        newDroplet[1] = sensor[2]
        deletedDroplets.append(newDroplet)
        droplets[droplet[1]] = None

    if len(result) != 0:
        sensors[i] = None

deletedDroplets.sort(key= lambda x: x[2])
def search(index):
    for deletedDroplet in deletedDroplets:
        if (deletedDroplet[2] == index):
            return True
    return False

for i in range(D):
    if search(i):
        print(deletedDroplets[i][1])

    else:
        print(0)
    






