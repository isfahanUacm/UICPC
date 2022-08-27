m = int(input())


def array_2d(n):
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    return a


arr = array_2d(m)
answers = []
length = arr[0].copy()
indexs = [0]
plus = 0

while True:
    minn = 1000000000
    indexMin = 1000000000
    for i, n in enumerate(length):
        if n != 0 and n < minn:
            indexMin = i
            minn = n


    for i in indexs:
        if arr[i][indexMin] == minn:
            print(indexMin+1, i+1)
            plus += 1
            break

    indexs.append(indexMin)

    for i in range(m):
        if arr[indexMin][i] < length[i]:
            length[i] = arr[indexMin][i]

    if plus >= m-1:
        break
