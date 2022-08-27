n = int(input())


def array_2d(n):
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    return a


arr = array_2d(n)
answers = []

indexMin = []
for i in range(n):
    minn = 1000000000
    for j in range(n):
        if arr[i][j] != 0 and arr[i][j] < minn:
            indexMin = [j+1]
            minn = arr[i][j]
        elif arr[i][j] == minn:
            indexMin.append(j+1)
    for k in indexMin:
        if [k, i+1] not in answers:
            print(i+1, k)
            answers.append([i+1, k])

