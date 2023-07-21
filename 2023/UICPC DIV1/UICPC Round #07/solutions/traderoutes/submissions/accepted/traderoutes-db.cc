// O(n log^2 n)

#include <bits/stdc++.h>
using namespace std;

multiset<pair<int, int>> f(int v, const vector<vector<int>>& adj,
                           const vector<int>& B, const vector<int>& V) {
  multiset<pair<int,int>> res = { {V[v], v} };
  vector<multiset<pair<int, int>>> ms;
  for(int u : adj[v]) {
    ms.push_back(f(u, adj, B, V));
    if(ms.back().size() > res.size())
      res.swap(ms.back());
  }
  for(int i=0;i<ms.size();i++) res.merge(ms[i]);
  while(res.size() > B[v]) res.erase(res.begin());
  return res;
}

int main() {
  int n; cin >> n;
  vector<vector<int>> adj(n);
  for(int i=1;i<n;i++) {
    int p; cin >> p;
    --p; // ADDED BY ZAC TO ACCOMMODATE THE 0-BASED INDEXING SHIFT
    adj[p].push_back(i);
  }

  vector<int> B(n), V(n);
  for(int& x : B) cin >> x;
  for(int& x : V) cin >> x;

  multiset<pair<int, int>> ans = f(0, adj, B, V);
  int64_t sum = 0;
  for(auto [x, y] : ans) sum += x;

  vector<int> cities;
  for(auto [x, y] : ans) cities.push_back(y);
  sort(cities.begin(), cities.end());

  cout << sum << endl;
  cout << cities.size();
  for(int i=0;i<cities.size();i++) cout << " " << cities[i]+1; // ZAC EDIT: +1 for new indexing
  cout << endl;
}
