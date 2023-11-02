#include <bits/stdc++.h>

using namespace std;

int n, T;
long double a[10], b[10], c[10];

long double grade(long double a, long double b, long double c, long double t)
{
  return a*t*t + b*t + c;
}

// find w such that grade'(t) = lambda
long double find_t(long double a, long double b, long double c, long double lambda)
{
  long double w = (lambda - b) / (2*a);
  if (w < 0) return 0;
  if (w > T) return T;
  return w;
}

// find the total times corresponding to a lambda
long double lagrange(long double lambda, long double t[])
{
  long double total = 0.0;
  for (int i = 0; i < n; i++) {
    t[i] = find_t(a[i], b[i], c[i], lambda);
    total += t[i];
  }
  return total;
}

int main()
{
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
    assert(c[i] >= 0);
    assert(a[i]*T*T + b[i]*T + c[i] <= 100.0);
    assert(a[i] < 0);
    assert(b[i] > 0);
    assert(2*a[i]*T + b[i] >= -1e-10);
  }


  long double lo = 0, hi = 1;
  long double t[10];

  while (lagrange(lo, t) < T) {
    lo -= 1.0;
  }
  
  while (lagrange(hi, t) > T) {
    hi *= 2;
  }

  while (hi - lo > 1e-12) {
    long double mid = (lo+hi)/2;
    if (lagrange(mid, t) > T) {
      lo = mid;
    } else {
      hi = mid;
    }
  }

  long double ans = 0.0;
  for (int i = 0; i < n; i++) {
    ans += grade(a[i], b[i], c[i], t[i]);
  }
  cout << fixed << setprecision(10) << ans/n << endl;

  return 0;
}
	
