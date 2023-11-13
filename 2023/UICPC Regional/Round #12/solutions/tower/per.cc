#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1<<20];
int val[1<<20], seen[1<<20];

void dfs(int u, int &bal, long long &totv, int &maxv) {
  if (seen[u]) return;
  seen[u] = true;
  bal += adj[u].size()-2;
  totv += val[u]*(adj[u].size()-1);
  maxv = max(maxv, val[u]);
  for (auto x: adj[u])
    dfs(x, bal, totv, maxv);
}

int main(void) {
  int n, v = 0;
  scanf("%d", &n);
  unordered_map<int, int> idx;
  for (int i = 0; i < n; ++i) {
    int s, t;
    scanf("%d%d", &s, &t);
    int &si = idx[s], &ti = idx[t];
    if (!si) val[si = ++v] = s;
    if (!ti) val[ti = ++v] = t;
    adj[si].push_back(ti);
    adj[ti].push_back(si);
  }
  memset(seen, 0, sizeof(seen));
  long long tot = 0;
  for (int i = 1; i <= v; ++i) {
    if (!seen[i]) {
      int bal = 0, maxv = 0;
      dfs(i, bal, tot, maxv);
      if (bal < 0) tot += maxv;
    }
  }
  printf("%lld\n", tot);
}
