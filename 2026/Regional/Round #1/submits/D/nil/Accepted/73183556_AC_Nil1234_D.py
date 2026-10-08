import math

n = int(input())
s = int(input())
direction = input()

if direction == "R":
    print(s - 1, end=" ")
    print(math.ceil(abs(n - s - 1) / 2) + 1, end=" ")
    print(math.ceil(abs(n - s - 1) / 2) + 1)
if direction == "L":
    print(math.ceil(abs(s - 2) / 2) + 1, end=" ")
    print(math.ceil(abs(s - 2) / 2) + 1, end=" ")
    print(n - s)
