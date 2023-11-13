def comb(n, m):
    res = 1
    i = n
    j = 1
    while i>n-m:
        res *= i/j
        i -= 1
        j += 1

    return res

s = input()
arr = s.split(" ")

n = float(arr[0])
p = float(arr[1])

ratio = 1.000000 / p

tmp_r = 1.000000 - ratio

chance = int(ratio * n / tmp_r)


ans = chance * comb(n, p-1) / comb(chance+n, p)

formatted = "{:.7f}".format(ans)
print(formatted)

