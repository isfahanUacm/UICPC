// Even Ford-Fukerson works: O(N^2 + N*R) for this particular problem since
// maxflow <= N and the graph has size O(N + R).

#include <bits/stdc++.h>

const int INF = 1e9; // set >= max capacity

using namespace std;

vector<unordered_map<int, int>> g;
vector<int> par;

void init(int n) { g = vector<unordered_map<int, int>>(n); }
void add_edge(int u, int v, int c) { g[u][v] = c; }

int augment(int v, int pre, int t, int mn) {
  if (v == t) return mn;
  if (par[v] != -1) return 0;
  par[v] = pre;

  for (auto& p : g[v]) {
    if (p.second == 0) continue;
    int nxt = augment(p.first, v, t, min(mn, p.second));
    if (nxt) {
      p.second -= nxt;
      g[p.first][v] += nxt;
      return nxt;
    }
  }
  return 0;
}

// augment until done, the mincut is stored in par, no need to know flow value
void mincut(int s, int t) {
  do { par.assign(g.size(), -1);
  } while(augment(s, -2, t, INF));
}

int main() {
  int N, R;
  cin >> N >> R;

  string team, change;
  cin >> team >> change;

  init(2*N+2);

  auto in = [](int i) { return 2*i; };
  auto out = [](int i) { return 2*i+1; };
  int s = 2*N, t = 2*N+1;

  for (int i = 0; i < N; ++i) {
    if (change[i] != '?') {
      if (team[i] == change[i]) add_edge(s, in(i), 2);
      else add_edge(out(i), t, 2);
    }
    add_edge(in(i), out(i), 1);
  }

  while (R--) {
    int u, v;
    cin >> u >> v;
    --u; --v;
    add_edge(out(u), in(v), 2);
    add_edge(out(v), in(u), 2);
  }

  mincut(s, t);

  string final(N, '_');
  for (int i = 0; i < N; ++i)
    if (par[out(i)] != -1) final[i] = team[i];
    else if (par[in(i)] != -1) final[i] = 'X';
    else final[i] = (team[i] == 'A' ? 'B' : 'A');
  cout << final << endl;

  return 0;
}
