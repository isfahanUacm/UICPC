#!/usr/bin/python3
import sys

sys.setrecursionlimit(200000)

n = int(input())

out = [False for _ in range(n)]
step_l = [i for i in range(n)]
step_r = [i for i in range(n)]

def find(v, step, dep = 0):
    pv = v
    while pv != -1 and pv != n and step[pv] != pv: pv = step[pv]
    while pv != -1 and pv != n and v != pv: v, step[v] = step[v], pv
    return pv
    # if v == -1 or v == n: return v
    # if v != step[v]: step[v] = find(step[v], step)
    # return step[v]

vals = list(map(int, input().split()))

output = []

look = set(range(n))

while True:
    # print("Iter")
    nlook, oset = set(), set()
    for x in look:
        if out[x]: continue
        l, r = find(x-1, step_l), find(x+1, step_r)
        # print(l, x, r)
        if l == -1: l = x
        if r == n: r = x
        if vals[l] > vals[x] or vals[r] > vals[x]:
            oset.add(x)
            nlook.add(l)
            nlook.add(r)
    if not oset:
        oset = set(i for i in range(n) if not out[i])
        output.append(oset)
        break
    else:
        for x in oset: out[x], step_l[x], step_r[x] = True, x-1, x+1
        output.append(oset)
        look = nlook

print(len(output)-1)
for o in output: print(*[vals[i] for i in sorted(o)])
