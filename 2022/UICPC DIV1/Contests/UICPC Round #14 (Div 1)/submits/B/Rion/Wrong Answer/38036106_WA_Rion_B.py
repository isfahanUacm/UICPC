mylist = input().split()
N = int(mylist[0])
X = int(mylist[1])
Y = int(mylist[2])

def formula():
    sum_value = 1
    i = 0
    while (N + 1) - (i + 2) * X > 0 and (N + 1) - (i + 2) * Y > 0:
        sum_value += (2 ** i) * ((N + 1) - (i + 2) * X) * ((N + 1) - (i + 2) * Y)
        i += 1
    return sum_value % (10 ** 9 + 7)

print(formula())