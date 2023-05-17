#!/usr/bin/env python3
n, k = [int(x) for x in input().split()]

old_ex = 0.0

for i in range(k):
    new_ex = 0.0
    for j in range(1, n+1):
        if j > old_ex:
            new_ex += j
        else:
            new_ex += old_ex
    new_ex /= n
    old_ex = new_ex

print("{:0.8f}".format(new_ex))
