def ff(x):
    s = 0
    for i in range(len(str(x))):
        s += int(str(x)[i]) ** 2
    return s


def cyclefinding(x0):
    tortoise = ff(x0)
    hare = ff(ff(x0))
    # print(tortoise, hare)
    while tortoise != hare:
        tortoise = ff(tortoise)
        hare = ff(ff(hare))
        # print(tortoise, hare)
        if tortoise == 1 or hare == 1:
            return False
    return True


def primecheck(x):
    if x == 1:
        return False
    for i in range(2, int(x**0.5)+1):
        if x % i == 0:
            return False
    return True


if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        idx, n = map(int, input().split())
        if primecheck(n):
            if not cyclefinding(n):
                print(idx, n, 'YES')
            else:
                print(idx, n, 'NO')
        else:
            print(idx, n, 'NO')
