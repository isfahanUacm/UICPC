from math import ceil, floor

input1 = input()
inputs = input1.split(" ")
q = int(inputs[0])
m = int(inputs[1])
s = int(inputs[2])
l = int(inputs[3])
time = 0
r = l % m
if l > 0 and r != 0:
    time += int(l / m + 1) * q
elif r == 0 and l != 0:
    time += l / m * q
freeTime = (m - r) * q
if r == 0:
    freeTime = 0
if s > freeTime:
    time += ceil((s - freeTime) / m)

print(int(time))
