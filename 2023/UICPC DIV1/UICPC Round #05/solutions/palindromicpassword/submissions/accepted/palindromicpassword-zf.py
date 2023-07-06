#!/usr/bin/python3
for x in range(int(input())):
    num = int(input())
    best = 0
    for chop in range(1000):
        tnum = chop*1000 + (chop%10)*100 + (chop%100 - chop%10) + (chop//100)%10
        if abs(tnum-num) < abs(best-num): best = tnum
    print(best)
