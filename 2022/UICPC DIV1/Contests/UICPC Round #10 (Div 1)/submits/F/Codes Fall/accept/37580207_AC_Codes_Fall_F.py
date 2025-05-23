from math import gcd, sqrt

numbers = set()


def cf(num1, num2):
    g = gcd(num1, num2)
    for i in range(1, int(sqrt(g)) + 1):
        if g % i == 0:
            numbers.add(i)
            if g != i * i:
                numbers.add(int(g / i))


t = int(input())
for _ in range(t):
    w, l = list(map(lambda x: int(x), input().split()))

    numbers.clear()

    cf(w, l - 2)
    cf(w - 1, l - 1)
    cf(w - 2, l)
    numbers.add(2)

    n = sorted(list(numbers))

    print(len(n), end=" ")
    for i in n:
        print(i, end=" ")
    print()
