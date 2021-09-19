from math import ceil
d = int(input())
n = 1000000
for i in range(n):
    j2 = d + i ** 2
    j = j2 ** 0.5
    if j == ceil(j):
        print(i, int(j))
        exit(0)
print('impossible')
