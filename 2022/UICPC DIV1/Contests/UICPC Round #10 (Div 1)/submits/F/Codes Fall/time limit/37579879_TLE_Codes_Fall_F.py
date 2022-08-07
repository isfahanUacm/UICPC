from math import gcd
numbers = set()


def cf(num1, num2):
    g = gcd(num1, num2)
    for i in range(1, g+1):
        if g % i == 0:
            numbers.add(i)


t = int(input())
for _ in range(t):
    w, l = list(map(lambda x: int(x), input().split()))

    numbers.clear()

    cf(w, l-2)
    cf(w-1, l-1)
    cf(w-2, l)

    print(len(numbers), end=" ")
    for i in numbers:
        print(i, end=" ")
    print()
