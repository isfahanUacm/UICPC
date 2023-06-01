#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using pll = pair<ll, ll>;
const ll INF = (1ll<<62);

int main() {
  ll n, m, l;
  cin >> n >> m >> l;

  multiset<pll> events;
  events.emplace(0, +1);
  for (ll i = 0, f; i < n; ++i) {
    cin >> f;
    ll loc = l+((i&1)?f:-f);
    events.emplace(loc, (i&1)?+2:-2);
    l = 2*loc-l;
  }
  events.emplace(l, (n&1)?+1:-1);
  for (ll i = 0, c; i < m; ++i) {
    cin >> c;
    events.emplace(c, 0);
  }
  events.emplace(INF, 0);

  ll pre = -INF, tot = 0, num = 0;
  for (auto p : events) {
    // cout << p.first << ' ' << p.second << endl;
    tot += (p.first - pre)*num;
    num += p.second;
    pre = p.first;
    if (p.second == 0) {
      cout << tot << (p.first == INF ? '\n' : ' ');
      tot = 0;
    }
  }

  return 0;
}
