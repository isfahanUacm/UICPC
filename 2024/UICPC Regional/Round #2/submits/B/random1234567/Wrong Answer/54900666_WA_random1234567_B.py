MAX = 300
arr = [[0 for _ in range(4)] for _ in range(MAX)]


def reload():
    for i in range(MAX):
        for j in range(4):
            arr[i][j] = 0


def solve2():
    reload()
    num, c = map(int, input().split())

    for _ in range(c):
        all = input().split()
        for q in range(num):
            answer, T_F = all[2*q], all[2*q+1]
            arr[q][ord(answer[0]) - ord('A')] = 1 if T_F == 'T' else -1

    for q in range(num):
        found = False
        falses = 0

        for i in range(4):
            if arr[q][i] == 1:
                print(chr(ord('A') + i), end=' ')
                found = True
                break
            elif arr[q][i] == -1:
                falses += 1

        if not found:
            if falses == 3:
                for i in range(4):
                    if arr[q][i] == 0:
                        print(chr(ord('A') + i), end=' ')
            else:
                print('?', end=' ')

    print()  # To ensure correct line break between test cases if needed


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        solve2()
