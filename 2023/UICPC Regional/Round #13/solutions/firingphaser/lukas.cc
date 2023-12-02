// Solution by lukasP (Lukáš Poláček)
#include <algorithm>
#include <array>
#include <cmath>
#include <complex>
#include <cstdio>
#include <iostream>
#include <vector>

#define rep(i, a, b) for (__typeof(b) i = (a); (i) < (b); ++(i))

using point = std::complex<double>;
const double kEps = 1e-6;

unsigned longest(const std::vector<std::pair<double, double>> & intervals, int len) {
  size_t end = 0, res = 0;
  rep(start, 0, intervals.size()) {
    while (end < intervals.size() && intervals[start].second + len + kEps >= intervals[end].first) {
      ++end;
    }
    res = std::max(res, end - start);
  }
  return res;
}

point min_touch(point x) {
  if (abs(imag(x)) < kEps) {
    return {0, 0};
  }
  double root = std::cbrt(real(x) / imag(x));
  return {root, -1};
}

point find_touch(point a, point c, point p) {
  point orig(real(a), imag(c));
  return min_touch(p - orig);
}

double cross(const point & a, const point & b) { return imag(conj(a) * b); }
double dot(const point & a, const point & b) { return real(conj(a) * b); }

bool inside(double a, double b, double x) {
  return std::min(a, b) - kEps <= x && x <= std::max(a, b) + kEps;
}

int main() {
  int r, len;
  scanf("%d %d", &r, &len);
  std::vector<std::array<point, 4>> rectangles;
  rep(i, 0, r) {
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    rectangles.push_back({point(x1, y1), point(x1, y2), point(x2, y2), point(x2, y1)});
  }

  unsigned res = 0;
  rep(i, 0, r) rep(k, 0, 4) {
    std::vector<point> directions;
    rep(j, 0, r) if (j != i) {
      rep(l, 0, 4) {
        directions.push_back(rectangles[j][l] - rectangles[i][k]);

        rep(q, 0, j) if (q != i) {
          for (int o = 1; o <= 3; o += 2) {
            const auto & dir =
                l % 2 == 0
                    ? find_touch(rectangles[j][l], rectangles[q][(l + o) & 3], rectangles[i][k])
                    : find_touch(rectangles[q][(l + o) & 3], rectangles[j][l], rectangles[i][k]);
            directions.push_back(dir);
          }
        }
      }
    }
    directions.push_back(point(1, 0));
    directions.push_back(point(0, 1));

    for (const point & dir : directions) {
      if (dir == point(0, 0)) {
        continue;
      }

      const point & orig = rectangles[i][k];
      std::vector<std::pair<double, double>> intervals;
      rep(j, 0, r) {
        std::vector<double> times;
        rep(l, 0, 4) {
          const point & start = rectangles[j][l];
          const point & end = rectangles[j][(l + 1) & 3];
          const point cdir = end - start;
          if (fabs(cross(cdir, dir)) <= kEps) {  // parallel
            if (fabs(cross(cdir, rectangles[i][k] - start)) <= kEps) {
              times.push_back(dot(start - rectangles[i][k], dir) / abs(dir));
              times.push_back(dot(end - rectangles[i][k], dir) / abs(dir));
            }
          } else {
            if (real(start) == real(end)) {
              double dif = real(start) - real(orig);
              double time = dif / real(dir);
              double y = imag(time * dir + orig);
              if (inside(imag(start), imag(end), y)) {
                times.push_back(time * abs(dir));
              }
            } else {
              double dif = imag(start) - imag(orig);
              double time = dif / imag(dir);
              double x = real(time * dir + orig);
              if (inside(real(start), real(end), x)) {
                times.push_back(time * abs(dir));
              }
            }
          }
        }
        std::sort(times.begin(), times.end());
        if (!times.empty()) {
          intervals.emplace_back(times[0], times.back());
        }
      }
      std::sort(intervals.begin(), intervals.end());
      res = std::max(res, longest(intervals, len));
    }
  }
  std::cout << res << std::endl;
}
