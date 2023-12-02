import math
eps = 1e-9

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    def __sub__(self, p): return Point(self.x - p.x, self.y - p.y)
    def cross(self, p): return self.x*p.y - self.y*p.x
    def dot(self, p): return self.x*p.x + self.y*p.y
    def norm2(self): return self.dot(self)
    def norm(self): return math.sqrt(self.norm2())

def isect(P1, P2, Q1, Q2):
    dP = P2 - P1
    dQ = Q2 - Q1
    det = dP.cross(dQ)
    if det == 0: return []
    s = dQ.cross(P1-Q1)
    t = dP.cross(P1-Q1)
    return [s/det] if -eps <= t/det and t/det <= 1+eps else []

ans = 1

def try_line(P, Q, Rooms, L):
    global ans
    shift = L / (P-Q).norm()
    events = []
    for Room in Rooms:
        I = []
        for i in range(4):
            I.extend(isect(P, Q, Room[i-1], Room[i]))
        if I:
            I.sort()
            events.append((I[0] - eps, -1));
            events.append((I[-1] + shift + eps, +1));
    events.sort()
    cur = 0
    for (_, v) in events:
        cur -= v
        ans = max(ans, cur)

def poly_val(p, x):
    val = 0
    for c in reversed(p):
        val *= x
        val += c
    return val

def diff(p): return [i*p[i] for i in range(1, len(p))]

def poly_roots(p, xmin, xmax):
    if len(p) == 2: return [-p[0]/p[1]]
    lo = xmin
    res = []
    for dr in sorted(poly_roots(diff(p), xmin, xmax) + [xmax+1]):
        hi = dr
        sgn = poly_val(p, lo) > 0
        if sgn ^ (poly_val(p, hi) > 0):
            while hi-lo > eps:
                m = (lo+hi)/2
                if sgn ^ (poly_val(p, m) <= 0): lo = m
                else: hi = m
            res.append((lo+hi)/2)
        lo = dr
    return res

def try_slide(P1, P2, Q1, Q2, R, Rooms, L):
    dP = P2-P1
    dQ = Q2-Q1
    if dP.cross(dQ) == 0: return
    if dP.y == 0:
        (P1, Q1) = (Q1, P1)
        (P2, Q2) = (Q2, P2)
    RS = Point(R.x - P1.x, R.y - Q1.y)
    for x in poly_roots([-L*L*RS.x*RS.x, 2*L*L*RS.x, (RS.norm2()-L*L), -2*RS.x, 1.0],
                        min(Q1.x, Q2.x) - P1.x - eps, max(Q1.x, Q2.x) - P1.x + eps):
        try_line(R, Point(x + P1.x, Q1.y), Rooms, L)

def read_room():
    (x1, y1, x2, y2) = map(float, raw_input().split())
    return [Point(x1, y1), Point(x1, y2), Point(x2, y2), Point(x2, y1)]

(r, l) = map(int, raw_input().split())
Rooms = [read_room() for _ in range(r)]

for r1 in range(r):
    for i1 in range(4):
        for r2 in range(r):
            for i2 in range(4):
                if r1 < r2 or r1 == r2 and i1 < i2:
                    try_line(Rooms[r1][i1], Rooms[r2][i2], Rooms, l)
                if r1 == r2: continue
                for r3 in range(r1):
                    for i3 in range(4):
                        if r3 == r2: continue
                        try_slide(Rooms[r1][i1-1], Rooms[r1][i1],
                                  Rooms[r3][i3-1], Rooms[r3][i3],
                                  Rooms[r2][i2], Rooms, l);
print ans
