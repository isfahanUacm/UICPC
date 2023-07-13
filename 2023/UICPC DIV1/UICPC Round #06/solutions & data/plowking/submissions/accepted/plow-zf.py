#!/usr/bin/python3

n, m = map(int, input().split())
tot, excess = 0, m-(n-1)

j, k = 1, 1
while j <= m:
    tot += j
    if excess > 0:
        j += min(excess, k-1)
        excess -= k-1
    else:
        tot += (m*(m+1) - j*(j+1))//2
        break
    j += 1
    k += 1

print(tot)
