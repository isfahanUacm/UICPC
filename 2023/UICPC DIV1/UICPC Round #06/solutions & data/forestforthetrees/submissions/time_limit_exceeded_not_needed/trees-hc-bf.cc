#include <bits/stdc++.h>

using namespace std;

typedef long long coord;

coord gcd(coord a, coord b)
{
  if (!b) return a;
  return gcd(b, a%b);
}

int main()
{
  coord xb, yb, x1, x2, y1, y2;
  cin >> xb >> yb >> x1 >> y1 >> x2 >> y2;

  coord g = gcd(xb, yb);
  xb /= g;
  yb /= g;

  for (int i = 1; i < g; i++) {
    coord kx = i*xb, ky = i*yb;
    if (!(x1 <= kx && kx <= x2 && y1 <= ky && ky <= y2)) {
      cout << "No" << endl;
      cout << kx << ' ' << ky << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;

  return 0;
}
