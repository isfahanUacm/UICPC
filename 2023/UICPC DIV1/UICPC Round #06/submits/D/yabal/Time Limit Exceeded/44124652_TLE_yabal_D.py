n = int(input())
indices = []

hIndex = 1
for i in range(n):
    indices.append(int(input()))

while True:
    count = 0
    for i in indices:
        if i >= hIndex:
            count += 1
        if count == hIndex:
            break

    if count == hIndex:
        hIndex += 1
    else:
        hIndex -= 1
        break


print(hIndex)