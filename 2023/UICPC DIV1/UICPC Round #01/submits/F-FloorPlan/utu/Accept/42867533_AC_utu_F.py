n = int(input())

if (n % 2 == 1):
    k = (n - 1) // 2
    m = k + 1
elif (n % 4 == 0 and n % 8 != 0):
    y = (n - 4) // 8
    m = 2 * y + 2
    k = 2 * y
elif (n % 8 == 0):
    y = (n // 8) - 1
    k = 2 * y + 1
    m = 2 * y + 3
else:
    print("impossible")
    exit(0)

print(m, k)
