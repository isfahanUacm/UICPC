#!/usr/bin/python3

n, m = map(int, input().split())
tasks = list(map(int, input().split()))
quiet = list(map(int, input().split()))

tasks.sort()
quiet.sort()

n -= 1
m -= 1
tot = 0
while n >= 0 and m >= 0:
    if tasks[n] <= quiet[m]:
        m -= 1
        tot += 1
    n -= 1
print(tot)
