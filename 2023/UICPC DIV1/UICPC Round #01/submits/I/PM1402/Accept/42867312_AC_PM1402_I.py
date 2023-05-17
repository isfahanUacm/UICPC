n = int(input())
a = [int(input()) for i in range(n)]

prefix_sums = [0]
for i in range(n):
    prefix_sums.append(prefix_sums[-1] + a[i]**2)


suffix_sums = [0]
for i in range(n-1, -1, -1):
    suffix_sums.append(suffix_sums[-1] + a[i])


suffix_sums = suffix_sums[::-1]


max_val = 0
for i in range(1, n):
    val = prefix_sums[i] * suffix_sums[i]
    if val > max_val:
        max_val = val

print(max_val)