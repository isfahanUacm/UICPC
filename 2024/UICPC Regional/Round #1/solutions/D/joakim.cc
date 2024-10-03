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
  ll r;
  cin>>r;
  tuple<ll,ll,ll> best = {1e18,-1,-1};
  rep(x,0,r+1) {
    ll a = 0, b = r+1;
    while(a+1 != b) {
      ll y = (a+b)/2;
      if(x*ll(x) + y*y > r*r) b = y;
      else a = y;
    }
    debug(x,b);
    best = min(best, {x*x+b*b,x,b});
  }
  cout << get<1>(best) << " " << get<2>(best) << endl;
}
