n = int(input())
sum = 0

for i in range(n):
    num = input().split(" ")
    x = float(num[0])
    y = float(num[1])
    sum += x * y

print("{:.3f}".format(sum))