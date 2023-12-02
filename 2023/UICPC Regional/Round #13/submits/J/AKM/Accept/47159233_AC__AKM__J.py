

s = input()
arr = s.split(" ")
n = int(arr[0])
mon = int(arr[1])
name = ""
val = ""
person = []
for i in range(n):
    s = input()
    arr = s.split(" ")
    name = arr[0]
    val = int(arr[1])
    t = [val, name]
    person.append(t)

person.sort()
ans = []
ind = n-1
while ind >= 0:
    if person[ind][0] <= mon:
        ans.append(person[ind][1])
        mon -= person[ind][0]
    ind -= 1

if mon == 0:
    print(len(ans))
    for i in ans:
        print(i)
else:
    print(0)