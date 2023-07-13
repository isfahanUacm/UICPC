n = int(input())
indices = []

for i in range(n):
    indices.append(int(input()))

indices = sorted(indices, reverse=True)

for i in indices:
    hIndex = i
    count = 0
    for i in indices:
        if i >= hIndex:
            count += 1
        else:
            break

    if count >= hIndex:
         break


print(hIndex)