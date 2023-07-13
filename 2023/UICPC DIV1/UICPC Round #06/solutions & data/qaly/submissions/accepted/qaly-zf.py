#!/usr/bin/python3

qaly = 0
for x in range(int(input())):
    a, b = map(float, input().split())
    qaly += a*b
print("{0:.3f}".format(qaly))
