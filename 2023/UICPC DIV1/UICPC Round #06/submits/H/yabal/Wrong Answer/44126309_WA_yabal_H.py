input1 = input()
inputs = input1.split(" ")
q = int(inputs[0])
m = int(inputs[1])
s = int(inputs[2])
l = int(inputs[3])
time = 0
r = l % m
if l>0:
    time += int(l / m + 1) * q
freeTime = (m - r) * q
if s > freeTime:
    time += s - freeTime

print(time)
