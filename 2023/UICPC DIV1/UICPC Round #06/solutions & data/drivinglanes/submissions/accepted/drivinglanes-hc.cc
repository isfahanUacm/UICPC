#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, m;
ll k, r;
ll len[250];
ll curve_len[250], curve_c[250];

// DP[i][j] = best after i straight roads, ending in lane j
// -2 == not possible
// -1 == uninitialized
ll DP[251][251];

int prev_l[251][251];

ll f(int num, int lane)
{
  if (num == 0) {
    return DP[num][lane] = (lane == 1) ? 0 : -2;
  }
  if (DP[num][lane] != -1) {
    return DP[num][lane];
  }

  DP[num][lane] = -2;
  ll straight = len[num-1];
  for (int prev_lane = 1; prev_lane <= m; prev_lane++) {
    int diff = abs(prev_lane - lane);
    ll prev = f(num-1, prev_lane);
    if (diff*k > straight || prev == -2) continue;
    ll seg = len[num-1] + diff*r +
      curve_len[num-1] + curve_c[num-1]*prev_lane + prev;

    if (DP[num][lane] == -2 || seg < DP[num][lane]) {
      DP[num][lane] = seg;
      prev_l[num][lane] = prev_lane;
    }
  }

  return DP[num][lane];

}

void trace(int n, int m)
{
  int max_lane = 1;
  while (n > 0) {
    m = prev_l[n][m];
    n--;
    max_lane = max(m, max_lane);
#ifdef DEBUG
    cout << n << ' ' << m << endl;
#endif
  }
#ifdef MAXLANE
  cout << "*** " << max_lane << endl;
#endif
}

int main()
{
  cin >> n >> m;
  cin >> k >> r;
  for (int i = 0; i < n; i++) {
    cin >> len[i];
  }
  curve_len[0] = curve_c[0] = 0;
  for (int i = 1; i < n; i++) {
    cin >> curve_len[i] >> curve_c[i];
  }
  
  for (int i = 0; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      DP[i][j] = -1;
    }
  }

#ifdef DEBUG
  for (int i = 0; i <= n; i++) {
    cout << "i = " << i << ": ";
    for (int j = 1; j <= m; j++) {
      cout << f(i,j) << ' ';
    }
    cout << endl;
  }

  for (int i = 0; i <= n; i++) {
    cout << "i = " << i << ": ";
    for (int j = 1; j <= m; j++) {
      cout << prev_l[i][j] << ' ';
    }
    cout << endl;
  }
#endif
  cout << f(n, 1) << endl;
  trace(n, 1);
  
  return 0;
}
