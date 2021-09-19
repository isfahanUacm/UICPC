li = [list(map(int, input().split())) for i in range(4)]
a = int(input())
if a == 0:
    for i in range(4):
        for l in range(2):
            for j in reversed(range(3)):
                if li[i][j] == 0:
                    li[i][j] = li[i][j+1]
                    li[i][j+1] = 0
        for j in range(3):
            if li[i][j] == li[i][j + 1]:
                li[i][j] += li[i][j + 1]
                li[i][j + 1] = 0
            for k in range(j, 3):
                if li[i][k] == 0:
                    li[i][k] = li[i][k+1]
                    li[i][k+1] = 0
elif a == 1:
    for i in range(4):
        for l in range(2):
            for j in reversed(range(3)):
                if li[j][i] == 0:
                    li[j][i] = li[j+1][i]
                    li[j+1][i] = 0
        for j in range(3):
            if li[j][i] == li[j+1][i]:
                li[j][i] += li[j+1][i]
                li[j+1][i] = 0
            for k in range(j, 3):
                if li[k][i] == 0:
                    li[k][i] = li[k+1][i]
                    li[k+1][i] = 0
elif a == 2:
    for i in range(4):
        for l in range(2):
            for j in range(1, 4):
                if li[i][j] == 0:
                    li[i][j] = li[i][j-1]
                    li[i][j-1] = 0
        for j in reversed(range(1, 4)):
            if li[i][j] == li[i][j-1]:
                li[i][j] += li[i][j-1]
                li[i][j-1] = 0
            for k in reversed(range(1, j)):
                if li[i][k] == 0:
                    li[i][k] = li[i][k - 1]
                    li[i][k - 1] = 0
else:
    for i in range(4):
        for l in range(4):
            for j in range(1, 4):
                if li[j][i] == 0:
                    # print("a", j, i, l)
                    li[j][i] = li[j-1][i]
                    li[j-1][i] = 0
        # print(li)
        for j in reversed(range(1, 4)):
            if li[j][i] == li[j-1][i]:
                # print("b", j, i)
                li[j][i] += li[j-1][i]
                li[j-1][i] = 0
            for k in reversed(range(1, j)):
                if li[k][i] == 0:
                    # print("c", j, i)
                    li[k][i] = li[k-1][i]
                    li[k-1][i] = 0

for i in range(4):
    for j in range(4):
        print(li[i][j], end=' ')
    print("")
