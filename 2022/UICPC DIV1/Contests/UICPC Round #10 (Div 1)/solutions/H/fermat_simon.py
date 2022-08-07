from math import sqrt
epsilon = 1e-6

def scalar(v1, v2):
  return sum(x1*x2 for x1,x2 in zip(v1, v2))
def vect(p1, p2):
  return [x2-x1 for x1,x2 in zip(p1, p2)]
def dist(p1, p2):
  return sqrt(scalar(*[vect(p1,p2)]*2))

def minimize(inf, sup, f):
  while sup - inf > epsilon:
    a, b = (2*inf+sup)/3, (inf+2*sup)/3
    if f(a) < f(b):
      sup = b
    else:
      inf = a
  return f((inf+sup)/2)


def median_fast(pts):
  a = dist(pts[0], pts[1])
  b = dist(pts[0], pts[2])
  c = dist(pts[1], pts[2])
  if c**2 > a**2+b**2+a*b: return a+b
  if b**2 > a**2+c**2+a*c: return a+c
  if a**2 > b**2+c**2+b*c: return b+c
  x = sqrt(3*(a+b+c)*(a+b-c)*(a+c-b)*(b+c-a))
  return sqrt((a**2+b**2+c**2+x)/2)

def median(pts, c=[]):
  #print("median", pts, c)
  n, i = len(pts[0]), len(c)
  if i == n:
    return sum(dist(c,p) for p in pts)
  f = lambda x: median(pts, c+[x])
  inf = min(p[i] for p in pts)
  sup = max(p[i] for p in pts)
  return minimize(inf, sup, f)

def best(pts, c=[]):
  #print("best", pts, c)
  n, i = len(pts[0]), len(c)
  if i == n:
    return max(median_fast([c]+pts[:i]+pts[i+1:])
                  for i in range(len(pts)))
  f = lambda x: best(pts, c+[x])
  inf = min(p[i] for p in pts)
  sup = max(p[i] for p in pts)
  return minimize(inf, sup, f)


pts = [list(map(int, input().split())) for _ in range(3)]
print(best(pts))
