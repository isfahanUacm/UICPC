#include <bits/stdc++.h>
using namespace std;

struct Bipartite {
  Bipartite(int n) : n(n), adj(n), mate(n, -1), delL(n), delR(n) {}

  void AddEdge(int u, int v) { adj[u].push_back(v); }
  void DeleteLVertex(int u) { delL[u] = true; }
  void DeleteRVertex(int u) { delR[u] = true; }

  pair<vector<bool>, vector<bool>> Cover() {
    for(int v=0; v<n; v++) {
      used.assign(n, false);
      usedR.assign(n, false);
      f(v);
    }

    vector<int> inv_mate(n, -1);
    for(int v=0;v<n;v++) if(mate[v] >= 0) inv_mate[mate[v]] = v;

    used.assign(n, false);
    usedR.assign(n, false);
    for (int v=0;v<n;v++)
      if(inv_mate[v] == -1)
        f(v);

    vector<bool> L(n), R(n);
    for(int l=0;l<n;l++)
      if (!used[l] || delL[l]) L[l] = true;
    for(int r=0;r<n;r++)
      if (usedR[r] || delR[r]) R[r] = true;
    return {L, R};
  }

  bool f(int v) {
    if(delL[v]) return false;
    if(used[v]) return false;
    used[v] = true;

    for(int u : adj[v]) {
      if(delR[u]) continue;
      usedR[u] = true;
      if(mate[u] == -1 || f(mate[u])) {
        mate[u] = v;
        return true;
      }
    }
    return false;
  }

  int n;
  vector<vector<int>> adj;
  vector<bool> used, usedR;
  vector<int> mate;
  vector<bool> delL, delR;
};

int main() {
  int n, m; cin >> n >> m;
  string orig, now; cin >> orig >> now;
  vector<pair<int,int>> edges(m);
  for(auto& [u, v] : edges) cin >> u >> v;

  Bipartite G(n);
  for (int i=0;i<n;i++) {
    G.AddEdge(i, i);
    if(orig[i] != now[i] && now[i] != '?')
      G.DeleteLVertex(i);
    if(orig[i] == now[i] && now[i] != '?')
      G.DeleteRVertex(i);
  }

  for(auto [u, v] : edges) {
    G.AddEdge(u - 1, v - 1);
    G.AddEdge(v - 1, u - 1);
  }

  auto [same, diff] = G.Cover();

  string res(n, 'X');
  for(int i=0;i<n;i++) {
    if (same[i] && diff[i]) continue;
    assert(same[i] != diff[i]);
    if(!same[i]) res[i] = orig[i];
    else res[i] = (orig[i] == 'A' ? 'B' : 'A');
  }

  cout << res << endl;
}
