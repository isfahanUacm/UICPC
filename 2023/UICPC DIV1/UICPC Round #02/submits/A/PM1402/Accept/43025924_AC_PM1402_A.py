n = input().split()
number = input().split()
a = int(n[0])
b = int(n[1])
s = 0
count=0
for i in range(a):
    s += int(number[i])
    if s > b:
        break
    count+=1
print(count)
