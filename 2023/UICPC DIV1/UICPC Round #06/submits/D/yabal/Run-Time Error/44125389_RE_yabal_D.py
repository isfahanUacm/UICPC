n = int(input())
indices = []

for i in range(n):
    indices.append(int(input()))

indices.sort()
index = 0
hIndex = indices[index]

while True:
    count = 0
    for i in indices:
        if i >= hIndex:
            count += 1
        if count == hIndex:
            break

    if count == hIndex:
        index += 1
        hIndex = indices[index]
    else:
        index -= 1
        hIndex = indices[index]
        break


print(hIndex)