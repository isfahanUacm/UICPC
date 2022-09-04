def arr_2d(n):
    return [list(input()) for _ in range(n)]


board = arr_2d(5)
knight = 0

for i in range(5):
    for j in range(5):
        if board[i][j] == 'k':
            knight += 1

if knight != 9:
    print("invalid")
    exit()


for i in range(5):
    for j in range(5):
        if board[i][j] == 'k':
            if i > 1:
                if j > 0:
                    if board[i - 2][j - 1] == 'k':
                        print("invalid")
                        exit()
                if j < 4:
                    if board[i - 2][j + 1] == 'k':
                        print("invalid")
                        exit()
            if i < 3:
                if j > 0:
                    if board[i + 2][j - 1] == 'k':
                        print("invalid")
                        exit()
                if j < 4:
                    if board[i + 2][j + 1] == 'k':
                        print("invalid")
                        exit()
            if j > 1:
                if i > 0:
                    if board[i - 1][j - 2] == 'k':
                        print("invalid")
                        exit()
                if i < 4:
                    if board[i + 1][j - 2] == 'k':
                        print("invalid")
                        exit()
            if j < 3:
                if i > 0:
                    if board[i - 1][j + 2] == 'k':
                        print("invalid")
                        exit()
                if i < 4:
                    if board[i + 1][j + 2] == 'k':
                        print("invalid")
                        exit()

print("valid")
