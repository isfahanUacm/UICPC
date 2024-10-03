#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define debug(...) //ignore
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef long double ld;

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n, m;
  cin >> n >> m;
  vector<vi> g(n);
  rep(i,0,m) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  debug(g);

  ll cyclen = 1e9, cyccnt = 0;

  auto bfs = [&](int s) {
    vi dist(n,1e9);
    dist[s] = 0;
    queue<int> q{{s}};
    while(sz(q)) {
      int x = q.front();
      q.pop();
      for(int y : g[x]) if(dist[y] == 1e9) {
        dist[y] = dist[x]+1;
        q.emplace(y);
      }
    }

    rep(x,0,n) {
      int above = 0;
      for(int y : g[x]) if(dist[y] < dist[x]) ++above;
      if(above <= 1) continue;
      int len = 2*dist[x];
      if(len < cyclen) cyclen = len, cyccnt = 0;
      if(len == cyclen) cyccnt += above*(above-1)/2;
    }

    rep(x,0,n) {
      for(int y : g[x]) if(y < x && dist[x] == dist[y]) {
        int len = dist[x]+dist[y]+1;
        if(len < cyclen) cyclen = len, cyccnt = 0;
        if(len == cyclen) ++cyccnt;
      }
    }
  };

  rep(x,0,n) bfs(x);

  debug(cyclen);
  assert(cyccnt % cyclen == 0);
  cout << cyccnt/cyclen << endl;
}
