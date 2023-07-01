#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <limits>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)

const double EPS=1e-6;
const double INF=numeric_limits<double>::infinity();

bool LT(double x, double y) { return y-x>EPS; }
bool LE(double x, double y) { return x-y<EPS; }
bool EQ(double x, double y) { return abs(x-y)<EPS; }

struct pt {
  double x,y;
  pt() {}
  pt(double x_, double y_) : x(x_), y(y_) {}
  pt operator + (const pt& p) const { return pt(x+p.x,y+p.y); }
  pt operator - (const pt& p) const { return pt(x-p.x,y-p.y); }
};

bool operator < (const pt& p, const pt& q) {
  if (!EQ(p.y,q.y)) return p.y>q.y;
  return LT(p.x,q.x);
}

bool operator <= (const pt& p, const pt& q) {
  if (!EQ(p.y,q.y)) return p.y>q.y;
  return LE(p.x,q.x);
}

bool operator != (const pt& p, const pt& q) {
  return !(EQ(p.x,q.x) && EQ(p.y,q.y));
}

struct segment {
  pt a,b,v;
  double intersectx(double x) const {
    return a.y+(x-a.x)/v.x*v.y;
  }
  double intersecty(double y) const {
    return a.x+(y-a.y)/v.y*v.x;
  }
};

istream& operator >> (istream& i, pt& p) { return i >> p.x >> p.y; }
istream& operator >> (istream& i, segment& s) {
  i >> s.a >> s.b;
  if (s.b<s.a) swap(s.a,s.b);
  s.v=s.b-s.a;
  return i;
}
ostream& operator << (ostream& o, const pt& p) { return o << p.x << ' ' << p.y; }
ostream& operator << (ostream& o, const segment& s) { return o << s.a << " -- " << s.b; }

typedef vector<pt> VP;
typedef vector<segment> VS;

enum event_type {
  DELETE,HIT,ADD
};

struct event {
  pt p;
  event_type type;
  int s;
  event() {}
  event(const pt& p_, event_type type_, int s_) : p(p_), type(type_), s(s_) {}
};

bool operator < (const event& e, const event& f) {
  return f.p<e.p;
}
typedef priority_queue<event> PQ;

VS ramps;
#ifdef VISUAL_DEBUG
VP ballmoves;
#endif

struct cmpramp {
  bool operator () (int r_, int s_) const {
    const segment& r=ramps[r_];
    const segment& s=ramps[s_];
    if (s.a<r.a) return ! operator () (s_, r_);
    double rx=r.intersecty(s.a.y);
    return LT(rx,s.a.x);
  }
};
typedef set<int,cmpramp> SI;

void findhit(PQ& events, const pt& ball, int id) {
  pt xing(ball.x, ramps[id].intersectx(ball.x));
  if (ball < xing && ramps[id].a <= xing && xing <= ramps[id].b) {
    events.push(event(xing, HIT, id));
  }
}

/* Assumptions:
 * No crossing
 * No vertical segments
 */
int main() {
  int n;
  cin >> n;
  ramps=VS(n+1); // ramps[n] is not a real item
  FOR(i,0,n) cin >> ramps[i];
  PQ events;
  FOR(i,0,n) {
    events.push(event(ramps[i].a,ADD,i));
    events.push(event(ramps[i].b,DELETE,i));
  }
  pt ball;
  cin >> ball.x;
  ball.y = INF;
#ifdef VISUAL_DEBUG
  ballmoves.push_back(pt(ball.x,-390000));
#endif
  int ballin=-1;
  SI active;
  while(!events.empty()) {
    event e=events.top();events.pop();
    switch(e.type) {
    case ADD: {
      //cerr << "ADD " << e.p << endl;
      active.insert(e.s);
      findhit(events, ball, e.s);
      break;
    }
    case DELETE: {
      //cerr << "ERASE " << e.p << endl;
      active.erase(e.s);
      if (ballin==e.s) {
	ball=ramps[e.s].b;
	ballin=-1;
#ifdef VISUAL_DEBUG
	ballmoves.push_back(ball);
#endif
      }
      segment& test = ramps[n];
      test.a=ball;
      test.v=pt(1,0);
      test.b=test.a+test.v;
      auto it = active.lower_bound(n);
      if (it!=active.end()) {
	findhit(events, ball, *it);
      }
      if (it!=active.begin()) {
	--it;
	findhit(events, ball, *it);
      }
      break;
    }
    case HIT: {
      //cerr << "HIT " << e.p << endl;
      if (!EQ(e.p.x,ball.x)) break;
      if (ballin!=-1) break;
      if (!active.count(e.s)) break;
      ballin=e.s;
#ifdef VISUAL_DEBUG
      ballmoves.push_back(e.p);
#endif
      break;
    }
    }
  }
#ifdef VISUAL_DEBUG
  ballmoves.push_back(pt(ball.x,-500000));
  for (int i=0;i<n;++i) {
    const segment& s=ramps[i];
    printf("draw((%f,%f)--(%f,%f));\n",s.a.x,s.a.y,s.b.x,s.b.y);
  }
  for (int i=1;i<ballmoves.size();++i) {
    const pt& a=ballmoves[i-1];
    const pt& b=ballmoves[i];
    printf("draw((%f,%f)--(%f,%f),yellow);\n",a.x,a.y,b.x,b.y);
  }
#else
  printf("%.0f\n",ball.x);
#endif
}
