n = int(input())


def array_2d(n):
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))
    return a


arr = array_2d(n)

for i in range(n-1):
    print(1, i+2)

