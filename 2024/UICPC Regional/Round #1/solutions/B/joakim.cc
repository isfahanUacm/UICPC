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


void bad(string s = "NO") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin>>n;
  vector<vi> g(n);
  rep(i,1,n) {
    int x,y;
    cin>>x>>y;
    --x,--y;
    g[x].emplace_back(y);
    g[y].emplace_back(x);
  }

  function<pii(int,int)> dfsfar = [&](int x, int p) {
    pii res = {0,x};
    for(int y : g[x]) if(y != p) {
      auto [d,z] = dfsfar(y,x);
      res = max(res, {d+1,z});
    }
    return res;
  };
  auto [_,x] = dfsfar(0,-1);
  auto [d,y] = dfsfar(x,-1);

  vi ord, pth;
  function<bool(int,int)> dfspth = [&](int x, int p) {
    bool onpth = (x == y);
    for(int y : g[x]) if(y != p) {
      if(dfspth(y,x)) onpth = true;
    }
    if(onpth) pth.emplace_back(x);
    else ord.emplace_back(x);
    return onpth;
  };
  dfspth(x,-1);
  reverse(all(ord));

  if(sz(pth) <= 3) bad();

  cout << "YES" << endl;
  rep(i,2,sz(pth)) cout << 1+pth[i] << " ";
  cout << 1+pth[1] << " " << 1+pth[0];
  for(int x : ord) cout << " " << 1+x;
  cout << endl;
}
