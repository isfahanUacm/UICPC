from math import fabs, floor

firstLine = input().split(" ")
secondLine = input().split(" ")
seatCount = int(firstLine[0])
peopleCount = int(firstLine[1])
room = 0
people = list()
for i in range(peopleCount):
    people.append(int(secondLine[i]))
people.sort()
for i in range(len(people)):
    space = 0
    if i != len(people) - 1:
        space = fabs(people[i + 1] - people[i])
    else:
        space = seatCount - people[i] + people[0]
    if floor(space / 2)-1>0:
        room += floor(space / 2)-1
print(room)
