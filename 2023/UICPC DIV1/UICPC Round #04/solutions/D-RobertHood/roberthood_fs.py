#!/usr/bin/env python3
# Solution by Fredrik Svensson
import sys, math
from sys import stdin

def lenSq(x1, y1, x2, y2):
    dx = x1-x2
    dy = y1-y2
    return dx*dx + dy*dy

c = int(stdin.readline())
if (c <= 1):
    print('-1')
else:
    coordsMap = {}
    for i in range(0,c):
        (x,y) = (int(z) for z in stdin.readline().split(' '))
        coordsMap.setdefault(x, []).append(y)
    # Sort the input.
    xs = list(coordsMap.keys())
    xs.sort()
    coords = []
    for x in xs:
        coords.append(coordsMap[x])
        coords[-1].sort()
    # Find it!
    retSq = 0
    for i in range(0, len(xs)): # 2001
        x = xs[i]
        yMin = coords[i][0]
        yMax = coords[i][-1]
        for j in range(i, len(xs)): # 2001
            x2 = xs[j]
            y2Min = coords[j][0]
            y2Max = coords[j][-1]
            retSq = max(retSq, lenSq(x,yMin,x2,y2Max), lenSq(x,yMax,x2,y2Min))
    print('%.9lf' % (retSq**0.5))
sys.exit(0)
