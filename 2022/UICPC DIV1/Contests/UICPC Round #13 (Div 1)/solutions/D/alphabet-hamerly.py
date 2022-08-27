#!/usr/bin/python

import sys
import string
import math

chars = string.ascii_uppercase + " '"
table = {c: i for i, c in enumerate(chars)}

def dist(a, b):
    d = abs(table[a] - table[b])
    return d if d <= 14 else 28 - d

diameter = 60
speed = 15.0
circumference = math.pi * diameter
time_per_stack = circumference / len(chars) / speed

n = int(sys.stdin.readline())
for _ in range(n):
    line = sys.stdin.readline().rstrip()
    f = lambda i: dist(line[i], line[i+1])
    units_run = sum(map(f, range(len(line)-1)))
    time = len(line) + units_run * time_per_stack
    print '{0:0.10f}'.format(time)
