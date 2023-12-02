#!/usr/bin/env python3
previous = input()
n = int(input())
animals = [input() for i in range(n)]
starts = [0]*256
for a in animals:
    starts[ord(a[0])] += 1
res = '?'
for a in animals:
    if a[0] == previous[-1]:
        if res == '?':
            res = a
        if starts[ord(a[-1])] - (ord(a[0]) == ord(a[-1])) == 0:
            res = a + '!'
            break
print(res)
