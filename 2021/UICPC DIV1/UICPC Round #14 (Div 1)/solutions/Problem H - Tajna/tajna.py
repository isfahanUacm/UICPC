s = input()
n = len(s)
for c in reversed(range(1, int(n ** 0.5) + 1)):
    if not n % c:
        r = n // c
        res = ''
        for i in range(c):
            for j in range(r):
                res += s[j * c + i]
        print(res)
        break
