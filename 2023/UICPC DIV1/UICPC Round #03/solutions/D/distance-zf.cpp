#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(vector<ll>& v) {
  sort(v.begin(), v.end());
  ll tot = 0;
  for (int i = 1; i < v.size(); ++i) tot += i*(v.size()-i)*(v[i]-v[i-1]);
  return tot;
}

int main() {
  int n;
  cin >> n;
  vector<ll> x(n), y(n);
  for (int i = 0; i < n; ++i) cin >> x[i] >> y[i];

  cout << solve(x) + solve(y) << endl;

  return 0;
}
