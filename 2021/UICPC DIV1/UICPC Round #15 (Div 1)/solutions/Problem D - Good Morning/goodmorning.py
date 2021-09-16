accessible_from = {
    '0': ['1', '2', '4', '5', '7', '8', '0'],
    '1': ['1'],
    '2': ['1', '2'],
    '3': ['1', '2', '3'],
    '4': ['1', '4'],
    '5': ['1', '2', '4', '5'],
    '6': ['1', '2', '3', '4', '5', '6'],
    '7': ['1', '4', '7'],
    '8': ['1', '2', '4', '5', '7', '8'],
    '9': ['1', '2', '3', '4', '5', '6', '7', '8', '9']
}
feasible = [False for i in range(201)]
for i in range(1, 201):
    s = str(i)
    feasible[i] = True
    for j in range(1, len(s)):
        if s[j-1] not in accessible_from[s[j]]:
            feasible[i] = False
            break
t = int(input())
for _ in range(t):
    k = int(input())
    i = 0
    while True:
        if feasible[k + i]:
            print(k + i)
            break
        elif feasible[k - i]:
            print(k - i)
            break
        i += 1
