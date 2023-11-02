#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
bool dEqual(double x,double y) { return fabs(x-y) < EPS; }

struct Point {
  double x, y;
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

ostream & operator<<(ostream &os, Point p)
{
  return os << "(" << p.x << "," << p.y << ")";
}

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(double r,Point p){ p.x *= r; p.y *= r; return p; }
double operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
double len(Point p){ return sqrt(p*p); }
double cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

enum Orientation {CCW, CW, CNEITHER};

//------------------------------------------------------------------------------
// Colinearity test
bool colinear(Point a, Point b, Point c) { return dEqual(cross(b-a,c-b),0); }

//------------------------------------------------------------------------------
// Orientation test  (When pts are colinear: ccw: a-b-c  cw: c-a-b  neither: a-c-b)
Orientation ccw(Point a, Point b, Point c) { //
  Point d1 = b - a, d2 = c - b;
  if (dEqual(cross(d1,d2),0))
    if (d1.x * d2.x < 0 || d1.y * d2.y < 0)
      return (d1 * d1 >= d2*d2 - EPS) ? CNEITHER : CW;
    else return CCW;
  else return (cross(d1,d2) > 0) ? CCW : CW;
}


//------------------------------------------------------------------------------
// Intersection of lines (line segment or infinite line)
//      (1 == 1 intersection pt, 0 == no intersection pts, -1 == infinitely many
int intersect_line(Point a, Point b, Point c, Point d, Point &p,bool segment) {
  double num1 = cross(d-c,a-c), num2 = cross(b-a,a-c),denom = cross(b-a,d-c);
  if (!dEqual(denom, 0)) {
    double r = num1 / denom, s = num2 / denom;
    if (!segment || (0-EPS <= r && r <= 1+EPS && 0-EPS <= s && s <= 1+EPS)) {
      p = a + r*(b-a); return 1;
    } else return 0;
  }
  if(!segment) return dEqual(num1,0) ? -1 : 0; // For infinite lines, this is the end
  if (!dEqual(num1, 0)) return 0;
  if(b < a) swap(a,b); if(d < c) swap(c,d);
  if (a.x == b.x) {
    if (b.y == c.y) { p = b; return 1; }
    if (a.y == d.y) { p = a; return 1; }
    return (b.y < c.y || d.y < a.y) ? 0 : -1;
  } else if (b.x == c.x) { p = b; return 1; }
  else if (a.x == d.x) { p = a; return 1; }
  else if (b.x < c.x || d.x < a.x) return 0;
  return -1;
}

int main()
{
  double x[2];
  cin >> x[0] >> x[1];

  int c1 = 0, c2 = 1;

  if (x[c1] > x[c2]) swap(c1, c2);      // c1 is always the trailing car
  x[c1] += 4.5;

  int n[2];
  Point p[2][100001];

  for (int c = 0; c < 2; c++) {
    p[c][0].x = 0;
    p[c][0].y = x[c];
    cin >> n[c];
    for (int i = 1; i <= n[c]; i++) {
      cin >> p[c][i].x;
      if (i % 2 == 0) {
	x[c] += p[c][i].x - p[c][i-1].x;
      }
      p[c][i].y = x[c];
    }
  }
  /*
  cout << n[c1] << ", " << n[c2] << endl;

  for (int i = 0; i <= n[c1]; i++) {
    cout << p[c1][i] << endl;
  }

  cout << "===" << endl;
  for (int i = 0; i <= n[c2]; i++) {
    cout << p[c2][i] << endl;
  }
  cout << "===" << endl;
  */
    
  int i2 = 1;
  Point pp;
  for (int i1 = 1; i1 <= n[c1]; i1++) {
    while (i2 <= n[c2] && p[c2][i2].x < p[c1][i1-1].x) {
      i2++;
    }

    for (int j = i2; j <= n[c2] && p[c2][j-1].x <= p[c1][i1].x; j++) {
      if (intersect_line(p[c1][i1-1], p[c1][i1], p[c2][j-1], p[c2][j],
			 pp, true)) {
	cout << "bumper tap at time " << (int)floor(pp.x + 0.5) << endl;
	return 0;
      }
    }
  }

  if (n[c1] % 2 == 1) {
    // car 1 keeps moving
    for (i2 = 1; i2 <= n[c2]; i2++) {
      if (p[c1][i2].x < p[c1][n[c1]].x) continue;

      Point pinf;
      pinf.x = p[c2][i2].x + 1;
      pinf.y = p[c1][n[c1]].y + pinf.x - p[c1][n[c1]].x;
      if (intersect_line(p[c1][n[c1]], pinf,
			 p[c2][i2-1], p[c2][i2], pp, true)) {
	cout << "bumper tap at time " << (int)floor(pp.x + 0.5) << endl;
	return 0;
      }
      i2++;
    }

    if (n[c2] % 2 == 0) {
      // car 2 stops
      double t = p[c2][n[c2]].y - p[c1][n[c1]].y + p[c1][n[c1]].x;
      cout << "bumper tap at time " << (int)floor(t + 0.5) << endl;
      return 0;
    }
  }

  cout << "safe and sound" << endl;

  return 0;
}
