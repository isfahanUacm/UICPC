import math

nCars, carLength, P = map(int, input().split(' '))

distances = []
cars = [[i, 0] for i in range(nCars)]
doors = []
passengers = []
for i in range(P):
    passengers.append(int(input()))

trainLength = nCars * carLength

for i in range(0, nCars):
    doors.append((carLength * i) + (carLength /2))

for passengerPos in passengers:
    distance = passengerPos % carLength
    if distance == 0:
        distances.append(carLength // 2)

    elif distance > carLength // 2:
        distance = distance - carLength // 2
        distances.append(distance)

    elif distance < carLength // 2:
        distance = carLength // 2 - distance
        distances.append(distance)

    else:
        distances.append(distance)

    if passengerPos >= trainLength:
        cars[-1][1] += 1

    #elif passengerPos % carLength == 0:
     #   cars[(passengerPos // carLength + 1)][1] += 1

    else:
        cars[(passengerPos // carLength)][1] += 1

print(max(distances))
print(max(cars, key=lambda x: x[1])[1])

