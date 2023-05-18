number = int(input())
x = []
for j in range(number):
    x.append(input().split())
for i in range(number):
    if (x[i][1]) > "2010/1/1":
        print(f"{x[i][0]} eligible")
    elif (x[i][2]) > "1991/1/1":
        print(f"{x[i][0]} eligible")
    elif int(x[i][3]) < 41:
        print(f"{x[i][0]} coach petitions")
    else:
        print(f"{x[i][0]} ineligible")
