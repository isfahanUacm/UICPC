#!/usr/bin/python3
n, m, l = map(int, input().split())

events = [(0,+1)]
i = 0
for f in map(int, input().split()):
    loc = l + (f if (i&1) else -f)
    events.append((loc, (+2 if (i&1) else -2)))
    l = 2*loc-l
    i += 1
events.append((l, (+1 if (n&1) else -1)))

events += [(int(c),0) for c in input().split()] + [(1<<62,0)]

events.sort()

pre, tot, num = 0, 0, 0
out = []
for x, d in events:
    pre, tot, num = x, tot + (x-pre)*num, num + d
    if not d:
        out.append(tot)
        tot = 0
print(*out)
