#!/usr/bin/python3

import heapq

def area2(p, q, r):
    qx, qy = q[0]-p[0], q[1]-p[1]
    rx, ry = r[0]-p[0], r[1]-p[1]

    return abs((r[0]-p[0])*(q[1]-p[1]) - (r[1]-p[1])*(q[0]-p[0]))

n, m = map(int, input().split())

def find(x, uf):
    if x != uf[x]:
        uf[x] = find(uf[x], uf)
    return uf[x]

pq = []
pts = []
ufl = []
ufr = []
for i in range(n+1):
    ufl.append(i)
    ufr.append(i)
    x, y = map(int, input().split())
    pts.append((x,y))
    if i >= 2:
        tri = (area2(pts[i-2], pts[i-1], pts[i]), i-1, i-2, i)
        # pq.append(tri)
        heapq.heappush(pq, tri)
# heapq.heapify(pq) # this approach is marginally faster

for i in range(n-m):
    while True:
        tri = heapq.heappop(pq)
        if ufl[tri[2]] == tri[2] and ufr[tri[3]] == tri[3]:
            break
    print(tri[1])

    ufl[tri[1]] = tri[2]
    ufr[tri[1]] = tri[3]

    if tri[2] > 0:
        i0, i1, i2 = find(tri[2]-1, ufl), tri[2], tri[3]
        ntri = (area2(pts[i0], pts[i1], pts[i2]), i1, i0, i2)
        heapq.heappush(pq, ntri)

    if tri[3] < n:
        i0, i1, i2 = tri[2], tri[3], find(tri[3]+1, ufr)
        ntri = (area2(pts[i0], pts[i1], pts[i2]), i1, i0, i2)
        heapq.heappush(pq, ntri)
