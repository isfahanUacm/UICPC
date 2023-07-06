#!/usr/bin/python3
for b, p in [map(float, input().split()) for x in range(int(input()))]:
    print(*["{:0.10f}".format((b+i)*60/p) for i in range(-1, 2)])
