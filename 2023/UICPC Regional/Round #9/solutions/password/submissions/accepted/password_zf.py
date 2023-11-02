#!/usr/bin/python3

n = int(input())

l = []
for i in range(n):
    a,b = input().split()
    l.append((float(b), a))
l.sort()

l.reverse()

tot = 0

for i in range(n):
    tot += (i+1)*l[i][0]

print("{:.4f}".format(tot))
