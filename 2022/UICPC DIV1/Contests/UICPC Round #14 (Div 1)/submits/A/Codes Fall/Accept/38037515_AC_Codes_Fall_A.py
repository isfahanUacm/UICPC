n, m = list(map(int, input().split()))
moves = []
for _ in range(m):
    moves.append(list(map(int, input().split())))

f_houses = []
check_houses = [[1, 1]]
not_check_houses = [[1, 1]]
rest_house = set()

for i in moves:
    if i[0] < 0:
        f_houses.append(abs(i[0]))

while not_check_houses:
    copy_not_check_houses = not_check_houses.copy()
    not_check_houses = []
    for i, j in copy_not_check_houses:
        if i in f_houses:
            for move in moves:
                if (-1*i) == move[0]:
                    if [move[1], j] not in check_houses:
                        not_check_houses.append([move[1], j])
                        check_houses.append([move[1], j])
                elif move[0] == i and j:
                    if move[1] not in f_houses:
                        rest_house.add(move[1])
                    else:
                        if [move[1], 0] not in check_houses:
                            not_check_houses.append([move[1], 0])
                            check_houses.append([move[1], 0])

        else:
            rest_house.add(i)
            if j:
                for m in moves:
                    if m[0] == i:
                        if m[1] not in f_houses:
                            rest_house.add(m[1])
                        else:
                            if [m[1], 0] not in check_houses:
                                not_check_houses.append([m[1], 0])
                                check_houses.append([m[1], 0])

print(len(rest_house))
