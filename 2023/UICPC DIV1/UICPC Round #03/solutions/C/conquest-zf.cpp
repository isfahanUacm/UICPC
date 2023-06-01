#include <bits/stdc++.h>

using namespace std;

using vi = vector<int>;
using pii = pair<int, int>;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vi> g(n);
  while (m--) {
    int u, v;
    cin >> u >> v;
    g[--u].push_back(--v);
    g[v].push_back(u);
  }

  vi army(n);
  for (int& x : army) cin >> x;

  priority_queue<pii, vector<pii>, greater<pii>> pq;

  int tot = 0;
  vector<bool> seen(n, false);
  pq.emplace(army[0], 0);

  while (pq.size()) {
    int a, v;
    tie(a, v) = pq.top();
    pq.pop();
    if (v != 0 && a >= tot) break;
    if (seen[v]) continue;
    seen[v] = true;
    tot += a;
    for (int w : g[v]) pq.emplace(army[w], w);
  }

  cout << tot << endl;

  return 0;
}
