#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

struct Point {
  ll x, y;
};

istream &operator>>(istream &is, Point &p)
{
  return is >> p.x >> p.y;
}

ll direction(Point p1, Point p2, Point p3)
{
  ll x1 = p3.x - p1.x;
  ll y1 = p3.y - p1.y;
  ll x2 = p2.x - p1.x;
  ll y2 = p2.y - p1.y;
  return x1*y2 - x2*y1;
}

bool on_segment(Point p1, Point p2, Point p3)
{
  return ((p1.x <= p3.x && p3.x <= p2.x) || (p2.x <= p3.x && p3.x <= p1.x)) &&
    ((p1.y <= p3.y && p3.y <= p2.y) || (p2.y <= p3.y && p3.y <= p1.y));
}

bool intersect(Point a1, Point a2, Point b1, Point b2)
{
  ll d1 = direction(b1, b2, a1);
  ll d2 = direction(b1, b2, a2);
  ll d3 = direction(a1, a2, b1);
  ll d4 = direction(a1, a2, b2);

  if (((d1 > 0 && d2 < 0) || (d1 < 0 && d2 > 0)) &&
      ((d3 > 0 && d4 < 0) || (d3 < 0 && d4 > 0))) {
    return 1;
  } else {
    return (d1 == 0 && on_segment(b1, b2, a1)) ||
      (d2 == 0 && on_segment(b1, b2, a2)) ||
      (d3 == 0 && on_segment(a1, a2, b1)) ||
      (d4 == 0 && on_segment(a1, a2, b2));
  }
}

int W, P;
Point treasure;
Point wall[1000][2];
Point person[1000][2];

ll dist2(Point a, Point b)
{
  ll dx = a.x - b.x, dy = a.y - b.y;
  return dx*dx + dy*dy;
}

ll dot(Point p1, Point p2, Point q1, Point q2)
{
  ll dx1 = p2.x - p1.x, dy1 = p2.y - p1.y;
  ll dx2 = q2.x - q1.x, dy2 = q2.y - q1.y;
  return dx1*dx2 + dy1*dy2;
}

ll dot(Point p1, Point p2)
{
  return p1.x*p2.x + p1.y*p2.y;
}

  
bool see(int p)
{
  // too far
  if (dist2(person[p][0], person[p][1]) < dist2(person[p][0], treasure)) {
    //    cerr << "too far" << endl;
    return false;
  }

  // wrong way
  if (dot(person[p][0], person[p][1], person[p][0], treasure) < 0) {
    //    cerr << "wrong way" << endl;
    return false;
  }

  // blocked by wall
  for (int i = 0; i < W; i++) {
    if (intersect(person[p][0], treasure, wall[i][0], wall[i][1])) {
      //      cerr << "wall " << i+1 << endl;
      return false;
    }
  }

  // blocked by person
  for (int i = 0; i < P; i++) {
    if (i == p) continue;

    if (dot(person[p][0], treasure, person[p][0], person[i][0]) > 0 &&
	direction(person[p][0], person[i][0], treasure) == 0 &&
	dist2(person[p][0], treasure) >= dist2(person[p][0], person[i][0])) {
      //      cerr << "person " << i+1 << endl;
      return false;
    }
  }

  return true;
}

int main()
{
  cin >> W >> P;
  cin >> treasure;
  for (int i = 0; i < W; i++) {
    cin >> wall[i][0] >> wall[i][1];
  }
  for (int i = 0; i < P; i++) {
    cin >> person[i][0] >> person[i][1];
  }
  for (int i = 0; i < P; i++) {
    cout << (see(i) ? "visible" : "not visible") << endl;
  }

  
  return 0;
}
