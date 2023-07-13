#!/bin/python3

# This code is pretty slow because of promotion to BigInt.
# Python code is passable, just not when you implement it like this, haha.

from fractions import Fraction
import sys

class Point:
    def __init__(self,x=0,y=0):
        self.x, self.y = Fraction(x), Fraction(y)
        
    def __str__(self):
        return "({0}, {1})".format(self.x, self.y)
    
    def __repr__(self):
        return "({0}, {1})".format(self.x, self.y)
    
    def __eq__(self, other):
        return self.x == other.x and self.y == other.y
    
    def __lt__(self, other):
        return (self.y == other.y and self.x < other.x) or self.y < other.y
    
    def __add__(self,other):
        return Point(self.x+other.x,self.y+other.y)
    
    def __sub__(self,other):
        return Point(self.x-other.x,self.y-other.y)
    
    def __rmul__(self,other):
        return Point(other*self.x , other*self.y)
    
def cross(p,q):
    return p.x*q.y - p.y*q.x

def dot(p,q):
    return p.x*q.x + p.y*q.y;

def dist2(p,q):
    return dot(p-q, p-q)
    
class Line:
    def __init__(self,p,q):
        self.p, self.q = p, q
        
    def __eq__(self,other):
        return self.p == other.p and self.q == other.q
    
    def __repr__(self):
        return "{0}--{1}".format(self.p, self.q)
    
    def __str__(self):
        return "{0}--{1}".format(self.p, self.q)
    
def intersection_point(L1,L2):
    a, b, c, d = L1.p, L1.q, L2.p, L2.q
    num1, num2, den = cross(d-c,a-c), cross(b-a,a-c), cross(b-a,d-c)
    
    if den != Fraction(0):
        r,s = num1 / den, num2 / den
        if r < Fraction(0) or r > Fraction(1): return (0, None)
        if s < Fraction(0) or s > Fraction(1): return (0, None)
        return 1, a + r*(b-a)
    
    if num1 != Fraction(0): return (0, None)
    
    if b < a: a,b = b,a
    if d < c: c,d = d,c
    
    if a.x == b.x:
        if b.y == c.y: return (1, b)
        if a.y == d.y: return (1, a)
        return (0, None) if (b.y < c.y or d.y < a.y) else (-1, None)
    if b.x == c.x: return (1, b)
    if a.x == d.x: return (1, a)
    return (0, None) if (b.x < c.x or d.x < a.x) else (-1, None)


def orientation(L,r):
    c = cross(L.p - L.q, r - L.q)
    return 0 if c == 0 else (1 if c > 0 else -1)

def dist2_to_line(L,p):
    a, b, c = L.q.y - L.p.y, L.p.x - L.q.x, cross(L.q,L.p)
    n, d2 = (a*p.x + b*p.y + c), a*a + b*b
    return Fraction(n*n,d2)

# For debuging purposes
def reason_for_not_visible(s):
    #pass
    sys.stderr.write(s + "\n")

### Start of actual code...
W, P = [int(x) for x in input().split()]

tx, ty = input().split()
treasure = Point(tx, ty)

walls = []
for _ in range(W):
    px, py, qx, qy = input().split()
    walls.append( Line( Point(px,py) , Point(qx,qy) ) )

vision = []
person = []
for _ in range(P):
    px, py, qx, qy = input().split()
    vision.append( Line( Point(px,py) , Point(qx,qy) ) )
    person.append( Point(px,py) )

for i in range(P):
    visible = True

    to_treasure = Line(person[i], treasure)
    
    # In circle?
    if dist2(vision[i].p,vision[i].q) < dist2(person[i], treasure):
        reason_for_not_visible("Too far away\n")
        visible = False

    # On the right half of the circle?
    if dot(vision[i].q - vision[i].p, treasure - person[i]) < 0:
        reason_for_not_visible("Wrong side of the semi-circle\n")
        visible = False

    # Is there a wall in the way?
    for w in walls:
        k, pt = intersection_point(w, to_treasure)
        if k == 0: continue # No intersection
        if k == -1:
            reason_for_not_visible("Wall parallel and in the way\n")
            visible = False
        if k == 1:
            reason_for_not_visible("Wall in the way at the point " + str(pt) + "\n")
            visible = False

    # Is there a person in the way?
    for p in person:
        if p == person[i]: continue
        if orientation(to_treasure, p) != 0: continue
        if not min(treasure.x, person[i].x) <= p.x <= max(treasure.x,person[i].x): continue
        if not min(treasure.y, person[i].y) <= p.y <= max(treasure.y,person[i].y): continue
        reason_for_not_visible("Person at " + str(p) + " is in the way\n")
        visible = False

    print("visible" if visible else "not visible")
