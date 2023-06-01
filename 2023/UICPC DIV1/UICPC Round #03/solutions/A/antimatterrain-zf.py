#!/usr/bin/python3

L = 19
MAXN = (1<<L)
INF = 1<<30

# i, x1, x2, y
NONE = (-1, 0, 0, INF)

# INPUT

D, S = map(int, input().split())

objs = []
xvals = set()
for i in range(D):
    x, y = map(int, input().split())
    xvals.add(x)
    objs.append((i, x, -INF, y))

for i in range(D, D+S):
    x1, x2, y = map(int, input().split())
    xvals.update((x1, x2))
    objs.append((i, x1, x2, y))

# COMPRESSION

xvals = sorted(xvals)
xmap = {xvals[i]:i for i in range(len(xvals))}
xmap[-INF] = -INF
mobjs = []
for o in objs: mobjs.append((o[0], xmap[o[1]], xmap[o[2]], o[3]))
objs = mobjs

# INITIALIZATION

rmq = [NONE]*(2*MAXN)
stacks = {i:[NONE] for i in range(MAXN)}
die = [0]*D
ykey = (lambda o : o[3])

# RMQ FUNCTIONS
def update(i, obj, lq = 0, hq = MAXN, node = 0):
    if lq+1 == hq:
        rmq[node] = obj
    else:
        left, mid, right = (node<<1)+1, (lq+hq)>>1, (node<<1)+2
        if i < mid: update(i, obj, lq, mid, left)
        else: update(i, obj, mid, hq, right)
        rmq[node] = min(rmq[left], rmq[right], key = ykey)

def query(lo, hi, lq = 0, hq = MAXN, node = 0):
    if hi <= lq or hq <= lo: return NONE
    if lo <= lq and hq <= hi: return rmq[node]

    mid = (lq+hq)>>1
    obj_l = query(lo, hi, lq, mid, (node<<1)+1)
    obj_r = query(lo, hi, mid, hq, (node<<1)+2)

    return min(obj_l, obj_r, key = ykey)

# PROCESSING FUNCTIONS
def addDrop(obj):
    stacks[obj[1]].append(obj)
    update(obj[1], obj)

def processSensor(obj):
    orig = query(obj[1], obj[2]+1)
    if orig == NONE: return

    hit = orig
    while hit[3] == orig[3]:
        die[hit[0]] = obj[3]
        stacks[hit[1]].pop()
        update(hit[1], stacks[hit[1]][-1])
        hit = query(obj[1], obj[2]+1)

# PROCESS
for obj in sorted(objs, key = ykey)[::-1]:
    if obj[2] == -INF: addDrop(obj)
    else: processSensor(obj)

print(*die, sep='\n')
