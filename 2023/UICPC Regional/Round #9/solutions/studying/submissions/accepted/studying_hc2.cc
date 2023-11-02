#include <bits/stdc++.h>

using namespace std;

int n, T;
long double a[10], b[10], c[10];

long double grade(long double a, long double b, long double c, long double t)
{
  return a*t*t + b*t + c;
}

long double f[10][20000];
long double m[10][20000];

int main()
{
  cin >> n >> T;
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i] >> c[i];
  }

  int blah = (int)sqrt(500000 / n / T);
  double r = 1.0 / blah;
  T *= blah;

  for (int i = 0; i < n; i++) {
    f[i][0] = 0;
    for (int j = 1; j <= T; j++) {
      f[i][j] = grade(a[i], b[i], c[i], r*j);
    }
  }

  copy(f[0], f[0]+T+1, m[0]);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < T; j++) {
      for (int k = 1; k + j <= T; k++) {
	if (m[i-1][j] + f[i][k] > m[i][k+j])
	  m[i][k+j] = m[i-1][j] + f[i][k];
      }
    }
  }
  

  cout << fixed << setprecision(10) << m[n-1][T]/n << endl;

  return 0;
}
	
