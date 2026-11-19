import math


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
        i %= MOD
        for c in range(i, count + i):
            category = math.ceil(c / k)
            r = (c % k + category - 1)
            index = a + c - i - 1
            # if 0 <= index < k:
            res[index] = k if r == 0 else r if r <= k else r % k
    if op == "?":
        i, j = map(int, inp[1:])
        c = counter(res[i - 1:j])
        for i in range(1, k + 1):
            result = c.get(i, None)
            if result is not None:
                print(result, end=" ")