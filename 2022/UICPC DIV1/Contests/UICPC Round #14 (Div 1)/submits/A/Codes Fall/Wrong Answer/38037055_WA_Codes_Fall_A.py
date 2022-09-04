n, m = list(map(int, input().split()))
moves = []
for _ in range(m):
    moves.append(list(map(int, input().split())))

f_houses = []
check_houses = []
not_check_houses = [1]
rest_house = set()

for i in moves:
    if i[0] < 0:
        f_houses.append(abs(i[0]))

while not_check_houses:
    copy_not_check_houses = not_check_houses.copy()
    not_check_houses = []
    for i in copy_not_check_houses:
        check_houses.append(i)
        if i in f_houses:
            for move in moves:
                if (-1*i) == move[0]:
                    if move[1] not in check_houses and move[1]not in not_check_houses:
                        not_check_houses.append(move[1])
                elif move[0] == i:
                    if move[1] not in f_houses:
                        rest_house.add(move[1])
                    else:
                        if move[1] not in check_houses and move[1] not in not_check_houses:
                            not_check_houses.append(move[1])

        else: # net have forces move
            rest_house.add(i)
            for m in moves:
                if m[0] == (-1*i):
                    if m[1] not in check_houses and m[1] not in not_check_houses:
                        not_check_houses.append(m[1])
                elif m[0] == i:
                    rest_house.add(m[1])

print(len(rest_house))
