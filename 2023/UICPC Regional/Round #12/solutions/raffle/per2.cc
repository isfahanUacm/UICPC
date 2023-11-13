#include <bits/stdc++.h>

int main(void) {
  int n, p;
  scanf("%d%d", &n, &p);
  double best = (double)1.0*p/(n+1);
  double prod = (double)p/(n+1);
  int bestm = 1;
  for (int m = 2; m <= 2*n; ++m) {
    prod *= (double)1.0*(n-p+m)/(n+m);
    double val = prod*m;
    if (val > best) {
      best = val;
      bestm = m;
    } 
  }
  printf("%.11lf\n", best);
}
