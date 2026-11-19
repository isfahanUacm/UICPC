def counter(nums):
    res = {}
    for num in nums:
        if num == 0:
            continue
        if num in res:
            res[num] += 1
        else:
            res[num] = 1
    return res


k, n, m = map(int, input().split())
MOD = k * k
res = [0] * n

for _ in range(m):
    inp = input().split()
    op = inp[0]
    if op == "+":
        i, a, b = map(int, inp[1:])
        count = b - a + 1
        i = (i - 1) % MOD
        for c in range(i, count + i):
            index = a + c - i - 1
            res[index] = (c % k + c // k) % k + 1
    if op == "?":
        i, j = map(int, inp[1:])
        c = counter(res[i - 1:j])
        print(*[c.get(x, 0) for x in range(1, k + 1)])