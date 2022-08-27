num = int(input())
bells = 0
for i in range(num):
    str1 = input()
    if str1 == "O":
        bells += 2**(num - i-1)
print(bells)