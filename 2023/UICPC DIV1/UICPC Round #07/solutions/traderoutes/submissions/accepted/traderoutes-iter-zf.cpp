#include <bits/stdc++.h>

#define MAXN 300000

using namespace std;

using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;

int p[MAXN], b[MAXN], v[MAXN], id[MAXN];
priority_queue<pii> keep[MAXN];

int main() {
  int n;
  cin >> n;
  for (int i = 1; i < n; ++i) { cin >> p[i]; --p[i]; }
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < n; ++i) cin >> v[i];
  iota(id, id+n, 0);

  for (int i = n-1; i >= 0; --i) {
    keep[id[i]].push({-v[i], i});
    while (keep[id[i]].size() > b[i]) keep[id[i]].pop();

    if (i) {
      if (keep[id[i]].size() > keep[id[p[i]]].size()) swap(id[i], id[p[i]]);
      while (keep[id[i]].size()) {
        keep[id[p[i]]].push(keep[id[i]].top());
        keep[id[i]].pop();
      }
    }
  }

  ll tot = 0;
  vi out;
  while (keep[id[0]].size()) {
    tot -= keep[id[0]].top().first;
    out.push_back(keep[id[0]].top().second);
    keep[id[0]].pop();
  }
  cout << tot << endl;
  sort(out.begin(), out.end());
  cout << out.size();
  for (int i = 0; i < out.size(); ++i) cout << ' ' << out[i]+1;
  cout << endl;

  return 0;
}
