#!/usr/bin/python3

# subtract s[i] from fort i value
def sub(f, s):
    for i in range(3):
        f[i] = (f[i][0] - s[i], f[i][1])

left = {"A":"B", "B":"C", "C":"A"}

# simulate one round, assumes all 3 f are still standing,
# sorted by value, and not all 3 are the same
def sim(f):
    assert 0 < f[0][0] and f[0][0] <= f[1][0] and f[1][0] <= f[2][0] and f[0][0] < f[2][0]

    shots = [0, 0, 0]

    # strongest fort
    if f[0][0] < f[1][0] or left[f[2][1]] == f[1][1]: shots[1] += 1
    else: shots[0] += 1

    # medium fort, uses sorted assumption
    shots[2] += 1

    # weakest fort
    if f[2][0] > f[1][0] or left[f[0][1]] == f[2][1]: shots[2] += 1
    else: shots[1] += 1

    sub(f, shots)

def solve(f):
    while True:
        f.sort()

        d1 = f[1][0] - f[0][0]
        d2 = f[2][0] - f[1][0]

        # all same ==> eventually all rubble
        if d1 == 0 and d2 == 0: return ["Rubble!"]

        # exactly two are already rubble
        elif f[1][0] == 0: return f[2]

        # exactly one is already rubble
        elif f[0][0] == 0: sub(f, [0, f[1][0], f[1][0]])

        # if the second smallest is small enough just simulate a step
        # (the second smallest goes down in every round)
        elif f[1][0] < 10: sim(f)

        # similarily, if the first two or second two are close but not equal,
        # just simulate (the gap will close)
        elif (d1 != 0 and d2 != 0) and ((1 <= d1 and d1 <= 3) or (1 <= d2 and d2 <= 3)): sim(f)

        # for min(d1, d2) many throws, the f will keep their relative
        # rankings so simulate them all at once
        elif min(d1, d2) >= 1: sub(f, [x*min(d1, d2) for x in [0, 1, 2]])

        # here d1 == 0 or d2 == 0 but not both

        # d1 == 0 and d2 >= 3: after every two rounds we are left with
        # f[0] and f[1] dropping by 1 and f[2] dropping by 4
        elif d2 >= 3: sub(f, [min(f[0][0] - 1, d2//3)*x for x in [1,1,4]])

        # d1 >= 3 and d2 == 0: after every two rounds the larger forts
        # both decreased by 3
        elif d1 >= 3: sub(f, [(d1//3)*x for x in [0, 3, 3]])

        # d1 == 1 or d2 == 1 (with the other being 0)
        # after every 3 rounds, every person has decreased by 3
        elif d1 == 1 or d2 == 1: sub(f, [(f[0][0]//3)*3]*3)

        # so d1 == 0 or d2 == 0 and the other is 2 or 3, just simulate
        # the gap will eventually close
        else: sim(f)




A, B, C = map(int, input().split())
print(*solve([(A,"A"), (B,"B"), (C,"C")])[::-1])
