#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
  vector<int> UF;
  UnionFind(int n) : UF(n) {
    iota(begin(UF), end(UF), 0);
  }

  int find(int u) { return UF[u] = (UF[u] == u ? u : find(UF[u])); }
  void merge(int u, int v) { UF[find(u)] = find(v); }
};

int64_t ch(int64_t n) { return n * (n - 1) / 2; }

int main() {
  cout << fixed << setprecision(10);
  int n, m, k=1; cin >> n >> m/* >> k*/;

  UnionFind UF(n);
  vector<vector<int>> adj(n);
  for(int i=0;i<m;i++) {
    int u, v/*, d*/; cin >> u >> v/* >> d*/;
    //if(d)
      UF.merge(u - 1, v - 1);
  }

  vector<int> sizes(n);
  for(int i=0;i<n;i++) sizes[UF.find(i)]++;

  int64_t num = 0;
  for(int i=0;i<n;i++) num += ch(sizes[i]);

  double q = 1 - num / 1. / ch(n);
  cout << 1 - pow(q, k) << endl;
}
