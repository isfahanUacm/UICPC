#!/usr/bin/python3

def value(quad, mu):
    tot = 0.0
    for a,b,c in quad:
        mui = max(mu-b, 0)
        tot += (mu - mui - b)/(2*a)
    return tot

n,t = map(int, input().split())

quad = []
for i in range(n):
    quad.append(list(map(float, input().split())))

low, high = -1.0, 1.0

while value(quad, low) < t: low -= low
while value(quad, high) > t: high += high

while low+1e-12 < high:
    #print(low, high, high-low)
    mid = (low+high)*0.5
    if value(quad, mid) > t: low = mid
    else: high = mid

tot = 0.0
for a,b,c in quad:
    mui = max(high-b,0)
    x = (high-mui-b)/(2*a)
    tot += (a*x + b)*x + c
print("{:.8f}".format(tot/n))
