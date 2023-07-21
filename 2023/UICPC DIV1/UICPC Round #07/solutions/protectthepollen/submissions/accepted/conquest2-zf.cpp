#include <bits/stdc++.h>

#define MAXN 510
#define MAXS 1010

using namespace std;

int s[MAXN], t[MAXN];
vector<int> g[MAXN];

int memo[MAXN][MAXS][2];
int eid[MAXN][MAXN];

int solve(int v, int p, int i, int b, int used) {
  if (i >= g[v].size()) return 0;
  int w = g[v][i];
  if (w == p) return solve(v, p, i+1, b, used);

  int& x = memo[eid[v][i]][b][used];
  if (x == -1)
    for (int bb = 0; bb <= b; ++bb) {
      int nxt = solve(v, p, i+1, b-bb, used);
      x = max(x, solve(w, v, 0, bb, 0) + nxt);
      if (used == 0 && s[w] <= bb) x = max(x, solve(w, v, 0, bb-s[w], 1) + t[w] + nxt);
    }

  return x;
}

int main() {
  int n, S;
  cin >> n >> S;
  for (int i = 1; i <= n; ++i) cin >> s[i] >> t[i];
  for (int i = 0, u = 0, v = 1; i < n; ++i) {
    if (i) cin >> u >> v;
    eid[u][g[u].size()] = eid[v][g[v].size()] = i;
    g[u].push_back(v);
    g[v].push_back(u);
  }

  memset(memo, -1, sizeof(memo));
  cout << solve(0, -1, 0, S, 0) << endl;

  return 0;
}
