// O(N * S^2)

#include <bits/stdc++.h>
using namespace std;

void combine(vector<int>& A, const vector<int>& B) {
  int n = A.size();
  for(int i=n-1;i>=0;i--)
    for(int j=0;i+j<n;j++)
      if(A[i] != -1 && B[j] != -1)
        A[i + j] = max(A[i + j], A[i] + B[j]);
}

pair<vector<int>, vector<int>> f(int v, int p, int S,
      const vector<vector<int>>& adj,
      const vector<int>& strength,
      const vector<int>& size) {
  vector<int> best_used(S+1, -1), best_dont(S+1, -1);
  if(size[v] <= S) best_used[size[v]] = strength[v];
  best_used[0] = best_dont[0] = 0;

  for(int u : adj[v]) {
    if (u == p) continue;
    auto [used, dont] = f(u, v, S, adj, strength, size);

    for(int i=0;i<=S;i++) used[i] = max(dont[i], used[i]);
    combine(best_dont, used);
    combine(best_used, dont);
  }
  return {best_used, best_dont};
}

int main() {
  int n, S; cin >> n >> S;
  vector<int> strength(n), size(n);
  for(int i=0;i<n;i++)
    cin >> size[i] >> strength[i];
  
  vector<vector<int>> adj(n);
  for(int i=0;i<n-1;i++) {
    int u, v; cin >> u >> v;
    adj[u-1].push_back(v-1);
    adj[v-1].push_back(u-1);
  }

  auto [used, dont] = f(0, -1, S, adj, strength, size);
  cout << max(*max_element(used.begin(), used.end()),
              *max_element(dont.begin(), dont.end())) << endl;
}
