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
  int n;
  cin >> n;
  ll ans = 0;
  vector<ll> v(n+2,1e18);
  rep(i,1,n+1) cin >> v[i];
  vector<ll> L(n+2), R(n+1);
  rep(i,1,n+1) {
    if(v[i] >= v[i-1]) L[i] = L[i-1];
    else L[i] = i;
  }
  for(int i = n; i >= 1; --i) {
    if(v[i] >= v[i+1]) R[i] = R[i+1];
    else R[i] = i;
  }

  rep(i,1,n+1) {
    if(v[i] >= v[i-1] && v[i] >= v[i+1]) {
      ll lo = max(v[L[i]],v[R[i]]);
      ans = max(ans, v[i]-lo);
    }
  }

  cout << ans << endl;
}
