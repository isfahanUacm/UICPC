#include <bits/stdc++.h>

#define MAXN 510
#define MAXS 1010

using namespace std;

int s[MAXN], t[MAXN];
vector<int> g[MAXN];

unordered_map<int, int> memo;

inline int comp(int v, int i, int b, int used) {
  return ((v*MAXN + i)*MAXS + b)*2 + used;
}

int solve(int v, int p, int i, int b, int used) {
  if (i >= g[v].size()) return 0;

  int w = g[v][i];
  if (w == p) return solve(v, p, i+1, b, used);

  int x = comp(v, i, b, used);
  if (memo.find(x) == memo.end()) {
    int y = 0;

    for (int bb = 0; bb <= b; ++bb) {
      int nxt = solve(v, p, i+1, b-bb, used);
      y = max(y, solve(w, v, 0, bb, 0) + nxt);
      if (used == 0 && s[w] <= bb) y = max(y, solve(w, v, 0, bb-s[w], 1) + t[w] + nxt);
    }

    memo[x] = y;
  }

  return memo[x];
}


int main() {
  int n, S;
  cin >> n >> S;
  for (int i = 1; i <= n; ++i) cin >> s[i] >> t[i];
  for (int i = 0, u, v; i < n-1; ++i) {
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  g[0].push_back(1);
  g[1].push_back(0); // maybe not needed

  cout << solve(0, -1, 0, S, false) << endl;

  return 0;
}
