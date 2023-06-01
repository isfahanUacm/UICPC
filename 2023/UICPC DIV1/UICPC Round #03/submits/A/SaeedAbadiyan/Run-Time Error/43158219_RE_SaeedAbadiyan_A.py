d, s = map(int, input().split())

sensors = []
for i in range(s):
    x1, x2, y = map(int, input().split())
    sensors.append((x1, x2, y))

for i in range(d):
    x, y = map(int, input().split())
    for sensor in sensors:
        if sensor[0] <= x <= sensor[1] and sensor[2] <= y:
            print(sensor[2])
            break
    else:
        print(0)