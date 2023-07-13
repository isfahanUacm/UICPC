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

  coord kmin = 1, kmax = g-1;
  kmin = max(kmin, (x1 + (xb-1))/xb);
  kmin = max(kmin, (y1 + (yb-1))/yb);
  kmax = min(kmax, x2/xb);
  kmax = min(kmax, y2/yb);
  if (kmin > kmax) {
    // cut trees do not matter
    if (g == 1) {
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
      cout << xb << ' ' << yb << endl;
    }
  } else if (kmin == 1 && kmax == g-1) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
    if (kmin > 1) {
      cout << xb << ' ' << yb << endl;
    } else {
      cout << xb*(kmax+1) << ' ' << yb*(kmax+1) << endl;
    }
  }
  
  return 0;
}
