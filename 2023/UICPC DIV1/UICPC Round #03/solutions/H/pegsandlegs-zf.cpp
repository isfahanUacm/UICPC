#include <bits/stdc++.h>

using namespace std;

int main() {
  int L, P;
  cin >> L >> P;
  int n = L+P;

  vector<double> e(n), p(n, 0.0);
  vector<bool> hit(n, false);
  for (int i = 0; i < L+P; ++i) {
    if (i < L) cin >> e[i];
    else {
      double pl, pr;
      int il, ir;
      cin >> pl >> pr >> il >> ir;
      --il; --ir;
      e[i] = pl*e[il] + pr*e[ir];
      p[i] = 1.0-pl-pr + pl*p[il] + pr*p[ir];
      hit[il] = hit[ir] = true;
    }
  }

  double best = 0.0;
  for (int i = 0; i < n; ++i) if (!hit[i]) best = max(best, e[i]/(1-p[i]));

  cout << fixed << setprecision(10) << best << endl;
}
