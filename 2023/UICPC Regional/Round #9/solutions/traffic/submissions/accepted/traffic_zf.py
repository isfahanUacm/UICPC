#!/usr/bin/python3

def solve(x1, x2, t1, t2):
    if x1 > x2:
        x1, x2 = x2, x1
        t1, t2 = t2, t1

    t1.append(10**9)
    t2.append(10**9)

    i1, i2, ct, d1, d2, crash = 0, 0, 0, 0, 0, -1

    while i1 < len(t1) and i2 < len(t2):
        delta = min(t1[i1], t2[i2]) - ct
        xx1 = x1 + delta*d1
        xx2 = x2 + delta*d2

        if xx1 + 5 > xx2: return ct + x2 - x1 - 4

        x1, x2 = xx1, xx2
        ct += delta

        if t1[i1] < t2[i2]:
            d1 = 1-d1
            i1 += 1
        else:
            d2 = 1-d2
            i2 += 1

    return -1


x1,x2 = map(int, input().split())

t1 = list(map(int, input().split()))
t2 = list(map(int, input().split()))

crash = solve(x1, x2, t1[1:], t2[1:])
if crash == -1: print("safe and sound")
else: print("bumper tap at time " + str(crash))
