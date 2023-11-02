#!/usr/bin/python3

n = int(input())
l = []
for i in range(n):
    a,b = input().split()
    if a.isalpha():
        b = int(b)
    else:
        a,b = b,int(a)//2
    l.append((b,a))
l.sort()
for a,b in l:
    print(b)
