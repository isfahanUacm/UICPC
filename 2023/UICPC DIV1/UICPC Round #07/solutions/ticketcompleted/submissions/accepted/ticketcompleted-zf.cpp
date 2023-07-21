#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const int MAXN = 100100;

ll uf[MAXN], sz[MAXN];

int find(int v) { return v == uf[v] ? v : (uf[v] = find(uf[v])); }

void merge(int u, int v) {
  u = find(u);
  v = find(v);

  if (u == v) return;
  uf[u] = v;
  sz[v] += sz[u];
}

int main() {
  ll n, m, k=1;
  cin >> n >> m;// >> k;

  fill(sz, sz+n, 1);
  iota(uf, uf+n, 0);

  for (int i = 0, u, v/*, p*/; i < m; ++i) {
    cin >> u >> v;// >> p;
    /*if (p)*/ merge(u-1, v-1);
  }

  ll bad = n*(n-1)/2;
  for (int v = 0; v < n; ++v)
    if (uf[v] == v) bad -= sz[v]*(sz[v]-1)/2;

  cout << fixed << setprecision(16) << 1.0-powf(double(bad)/(n*(n-1)/2), k) << endl;
}
