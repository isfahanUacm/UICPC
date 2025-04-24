from math import gcd
from collections import Counter

input()
counts = Counter(map(int, input().split(' ')))
nums = list(sorted(counts))

running_sum = 0

max_gcd = -1
left = -1
right = -1
for i in range(len(nums)-1):
    for j in range(i+1, len(nums)):
        g = gcd(nums[i], nums[j])
        if g > max_gcd:
            max_gcd = g
            left = nums[i]
            right = nums[j]

counts[left] -= 1
counts[right] -= 1

if counts[left] == 0:
    del counts[left]
    nums.remove(left)
if counts[right] == 0:
    del counts[right]
    nums.remove(right)

running_sum += max_gcd


while nums:
    max_gcd = 0
    max_n = None
    l = False
    for n in nums:
        gcdl = gcd(left, n)
        gcdr = gcd(right, n)
        
        if gcdl > max_gcd:
            max_gcd = gcdl
            l = True
            max_n = n
        if gcdr > max_gcd:
            max_gcd = gcdr
            l = False
            max_n = n

    running_sum += max_gcd
    if l:
        left = max_n
        # res.insert(0, max_n)
    else:
        right = max_n
        # res.append(max_n)
    counts[max_n] -= 1
    if not counts[max_n]:
        del counts[max_n]
        nums.remove(max_n)

    # print(running_sum, left, right)

print(running_sum)
# print(res)
