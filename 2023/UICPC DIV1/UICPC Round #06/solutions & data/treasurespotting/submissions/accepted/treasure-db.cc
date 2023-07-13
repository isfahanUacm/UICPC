#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct Point { ll x, y; };
ll dot   (Point p, Point q) { return p.x*q.x + p.y*q.y; }
ll cross (Point p, Point q) { return p.x*q.y - p.y*q.x; }
ll len2  (Point p)          { return dot(p,p); }
Point operator -(Point p, Point q) { return {p.x-q.x, p.y-q.y}; }
bool  operator==(Point p, Point q) { return p.x == q.x && p.y == q.y; }

int dir(Point p, Point q, Point r) {
  ll c = cross(q-p, r-q);
  if(c == 0) return 0;
  return (c < 0 ? -1 : 1);
}

bool on_seg(Point a, Point b, Point p){
  return (min(a.x,b.x) <= p.x && p.x <= max(a.x,b.x)) &&
    (min(a.y,b.y) <= p.y && p.y <= max(a.y,b.y));
}

bool intersect(Point a1, Point a2, Point b1, Point b2){
  int d1 = dir(a1,a2,b1), d2 = dir(a1,a2,b2);
  int d3 = dir(b1,b2,a1), d4 = dir(b1,b2,a2);
  if(d1 != d2 && d1 == -d2 && d3 != d4 && d3 == -d4) return true;

  return (d1 == 0 && on_seg(a1,a2,b1)) ||
    (d2 == 0 && on_seg(a1,a2,b2)) ||
    (d3 == 0 && on_seg(b1,b2,a1)) ||
    (d4 == 0 && on_seg(b1,b2,a2));  
}

vector<vector<Point> > wall, people;

bool visible(Point treasure, int idx){
  Point me = people[idx][0], circ = people[idx][1];
  
  // Outside of circle?
  if(len2(treasure-me) > len2(circ-me))   return false;
  
  // Not on right half of semi-circle?
  if(dot(treasure-me, circ-me) < 0)  return false;
  
  // Wall in the way?
  for(const auto& W : wall)
    if(intersect(treasure, me, W[0], W[1]))
      return false;

  // Person in the way?
  for(const auto& P : people)
    if(!(P[0] == me) && dir(P[0],me,treasure) == 0)
      if(len2(me-P[0]) < len2(me-treasure) &&
	 len2(treasure-P[0]) < len2(treasure-me))
	return false;
  
  return true;
}

int main(){
  int W, P; cin >> W >> P;
  Point treasure; cin >> treasure.x >> treasure.y;

  wall.assign(W, vector<Point>(2));
  for(auto& w : wall)
    for(int j=0;j<2;j++)
      cin >> w[j].x >> w[j].y;

  people.assign(P, vector<Point>(2));
  for(auto& p : people)
    for(int j=0;j<2;j++)
      cin >> p[j].x >> p[j].y;
  
  for(int i=0;i<P;i++)
    cout << (visible(treasure,i) ? "" : "not ") << "visible" << endl;
}
