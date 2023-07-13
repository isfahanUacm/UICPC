#!/usr/bin/python3

xb, yb = map(int, input().split())
x1, y1, x2, y2 = map(int, input().split())

def gcd(a, b): return a if b == 0 else gcd(b, a%b)

g = gcd(xb, yb)

xs1, ys1 = xb//g, yb//g
xs2, ys2 = xb-xs1, yb-ys1

def cut(x, y): return x1 <= x and x <= x2 and y1 <= y and y <= y2

if g == 1 or (cut(xs1, ys1) and cut(xs2, ys2)):
    print("Yes")
else:
    print("No")
    if not cut(xs1, ys1): d = 1
    else: d = min((y2+ys1)//ys1, (x2+xs1)//xs1)
    print(d*xs1, d*ys1)
