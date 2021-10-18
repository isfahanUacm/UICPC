#!/usr/bin/env python3
from heapq import heappush, heappop
from collections import defaultdict

N = int(input())
height = [int(x) for x in input().split()]

dist = {}
adj = defaultdict(list)
s = (-1, 0)
t = (N, 0)

# Construct the edges that correspond to bulldozing right.
stack = []
for i, h in enumerate(height):
    if h == 1:
        continue
    if h > 1:
        stack.append((i, h-1))
        continue
    if len(stack) == 0:
        continue

    # Case: h == 0 and len(stack) > 0.
    j, remainder = stack.pop()
    remainder -= 1
    adj[(j, remainder + 1)].append(((i, 1), i - j))
    if remainder != 0:
        stack.append((j, remainder))

dist_past_end = 0
while len(stack):
    j, remainder = stack.pop()
    cost = dist_past_end + remainder + (N - j - 1)
    adj[(j, 1)].append((t, cost))
    dist_past_end += remainder

# Now do the same thing, but bulldozing left.
for i, h in enumerate(reversed(height)):
    if h == 1:
        continue
    if h > 1:
        stack.append((i, h-1))
        continue
    if len(stack) == 0:
        continue

    # Case: h == 0 and len(stack) > 0.
    j, remainder = stack.pop()
    remainder -= 1
    adj[(N-i-1, 0)].append(((N-j-1, height[N-j-1] - remainder), i - j))
    if remainder != 0:
        stack.append((j, remainder))

dist_past_end = 0
while len(stack):
    j, remainder = stack.pop()
    cost = dist_past_end + remainder + (N - j - 1)
    adj[s].append(((N-j-1, height[N-j-1]), cost))
    dist_past_end += remainder


states_at = [set() for _ in range(N)]
for i in range(N):
    states_at[i].add(1)
    states_at[i].add(height[i])

for i, h in adj:
    if 0 <= i < N:
        states_at[i].add(h)
    for (j, k), _ in adj[(i, h)]:
        if 0 <= j < N:
            states_at[j].add(k)


for i in range(N):
    l = list(sorted(states_at[i]))    
    for j in range(len(l)-1):
        if l[j] == 0 and l[j+1] == 1:
            adj[(i, 0)].append(((i, 1), 0))
        else:
            adj[(i, l[j])].append(((i, l[j+1]), 2*(l[j+1]-l[j])))

adj[s].append(((0, min(1, height[0])), 0))
adj[(N-1, max(height[N-1], 1))].append((t, 0))
for i in range(N-1):
    adj[(i, max(height[i], 1))].append(((i+1, min(height[i+1], 1)), 0))

states = set([s, t])
for i in range(N):
    for h in states_at[i]:
        states.add((i, h))

dist = {s : 0}
pq = []
heappush(pq, (0, s))
while len(pq):
    d, v = heappop(pq)
    if d > dist[v]:
        continue

    for nb, w in adj[v]:
        if nb not in dist or d + w < dist[nb]:
            dist[nb] = d + w
            heappush(pq, (d+w, nb))

print(dist[t])
