#include <bits/stdc++.h>

using namespace std;

const double EPS = 1e-8;
bool dEqual(double x,double y) { return fabs(x-y) < EPS; }

struct Point {
  double x, y;
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(double r,Point p){ p.x *= r; p.y *= r; return p; }
double operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
double len(Point p){ return sqrt(p*p); }
double cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

enum Orientation {CCW, CW, CNEITHER};

void rotate(Point &dir, double angle)
{
  double theta = angle * acos(-1.0) / 180.0;
  double x = cos(theta)*dir.x - sin(theta)*dir.y;
  double y = sin(theta)*dir.x + cos(theta)*dir.y;
  dir.x = x;
  dir.y = y;
}
bool hit(Point p, Point &d, Point q, int radius, double &t)
{
  // look for the point p + t*d, t >= 0 that is the point of intersection
  //
  // (px + t*dx - qx)^2 + (py + t*dy - qy)^2 <= (2*r)^2
  //
  // (dx^2+dy^2)*t^2 + 2*(dx*(px - qx) + dy*(py-qy)) * t +
  //   px^2 - 2*px*qx + py^2 - 2*py*qy + qx^2 + qy^2 - 4*r^2 <= 0
  //
  // (d*d) * t^2 + 2 * d * (p-q) * t +
  //   (p*p) + (q*q) - 2*p*q - 4*r^2 <= 0

  double a = d * d;
  double b = 2 * (d * (p-q));
  double c = (p*p) + (q*q) - 2*(p*q) - 4*radius*radius;

  double disc = b*b-4*a*c;
  if (disc < 0) return false;

  double r1 = (-b - sqrt(disc)) / (2*a);
  double r2 = (-b + sqrt(disc)) / (2*a);

  if (max(r1, r2) < 0) return false;

  t = min(max(0.0, r1), max(0.0, r2));

  Point hit = p + t * d;
  d = q - hit;
  return true;
}

int main()
{
  Point p[3], dir;
  int radius;

  for (int i = 0; i < 3; i++) {
    cin >> p[i].x >> p[i].y;
  }
  cin >> dir.x >> dir.y >> radius;
  rotate(dir, -1.0);

  Point dir1 = dir, dir2 = dir;
  double t1, t2;
  
  bool hit2 = hit(p[0], dir1, p[1], radius, t1);
  bool hit3 = hit(p[0], dir2, p[2], radius, t2);

  if (!hit2 && !hit3) {
    cout << 5 << endl;
    return 0;
  }
  if (hit2 && hit3) {
    if (t1 < t2) hit3 = false;
    else hit2 = false;
  }
  if (hit2) {
    if (hit(p[1], dir1, p[2], radius, t1)) {
      cout << 1 << endl;
    } else {
      cout << 3 << endl;
    }
  } else {
    if (hit(p[2], dir2, p[1], radius, t2)) {
      cout << 2 << endl;
    } else {
      cout << 4 << endl;
    }
  }
  
  return 0;
}
