#!/usr/bin/python3

x,y,n = map(int, input().split())

for i in range(1,n+1):
    out = ""
    if i%x == 0: out = "Fizz"
    if i%y == 0: out += "Buzz"
    if out == "": out = i
    print(out)
