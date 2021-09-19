t = int(input())
while t:
    n = input()
    li = [int(n[:i]) for i in range(1, len(n)+1)]
    res = 0
    for digit in li:
        tmp = 0
        while digit:
            tmp += digit & 1
            digit >>= 1
        res = max(tmp, res)
    print(res)
    t -= 1
