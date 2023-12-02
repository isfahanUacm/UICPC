s = input()
arr = s.split(" ")
area = int(arr[0])
n = int(arr[1])
machin = []
for i in range(n):
    s = input()
    t = s.split(",")
    machin.append(t)
ans = []
best = 1e18
summ = 0
charge = 0
for i in range(n):

    charge = int(area / (int(machin[i][2]) * int(machin[i][3])))
    if area % (int(machin[i][2] * int(machin[i][3]))) != 0:
        charge += 1
    summ = charge * (int(machin[i][3]) + int(machin[i][4]))

    if summ <= 10080:
        if int(machin[i][1]) < best:
            best = int(machin[i][1])
            ans.clear()
            ans.append(machin[i][0])
        elif int(machin[i][1]) == best:
            ans.append(machin[i][0])
if len(ans) == 0:
    print("no such mower")
else:
    for i in ans:
        print(i)