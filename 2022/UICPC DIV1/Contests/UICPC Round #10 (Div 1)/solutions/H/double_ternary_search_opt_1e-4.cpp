#include <functional>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

const double eps = 1e-4;
double inf = 1;
const double magic = sqrt(3) / 2;

struct point {
  double x, y;
};

point operator+(point a, point b) {
  return point{a.x + b.x, a.y + b.y};
}

point operator-(point a, point b) {
  return point{a.x - b.x, a.y - b.y};
}

point operator*(double a, point v) {
  return point{a * v.x, a * v.y};
}

point perp(point a) {
  return point{-a.y, a.x};
}

double operator*(point a, point b) {
  return a.x * b.x + a.y * b.y;
}

double len(point a) {
  return sqrt(a * a);
}

double dist(point a, point b) {
  return len(a - b);
}

double close_enough(double x, double y) {
  return abs(x-y) < max(eps, eps*max(abs(x), abs(y)));
}


double ternaria(double a, double b, function<double(double)> f) {
  double low = f(a), high = f(b);
  while (1) {
    double l = (2 * a + b) / 3, r = (a + 2 * b) / 3;
    double fl = f(l), fr = f(r);
    if (close_enough(low, fl) and close_enough(fr, high)) break;
    if (fl < fr) {
      b = r;
      high = fr;
    } else {
      a = l;
      low = fl;
    }
  }
  return f((a + b) / 2);
}

double fermat(point a, point b, point c) {
  return ternaria(-inf, inf, [&](double x) {
      return ternaria(-inf, inf, [&](double y) {
	  point p{x, y};
	  return dist(a, p) + dist(b, p) + dist(c, p);
      });
  });
}

int main() {
  const int n = 3;
  vector<point> pts(n);
  for (int i = 0; i < n; ++i) {
    cin >> pts[i].x >> pts[i].y;
    inf = max(inf, max(abs(pts[i].x), abs(pts[i].y)));
  }
  cout.precision(10);
  cout << ternaria(-inf, inf, [&](double x) {
      return ternaria(-inf, inf, [&](double y) {
	  point p{x, y};
	  double ans = 0;
	  for (int i = 0; i < n; ++i) {
	    for (int j = i + 1; j < n; ++j) {
	      ans = max(ans, fermat(pts[i], pts[j], p));
	    }
	  }
	  return ans;
      });
  }) << endl;
}
