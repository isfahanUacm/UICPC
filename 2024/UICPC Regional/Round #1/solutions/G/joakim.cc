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
  int k, n;
  cin >> n >> k;
  vector<ld> p(n);
  rep(i,0,n) cin>>p[i];
  sort(all(p));
  reverse(all(p));

  vector<ld> dp(2*n+10);
  int off = n+5;
  dp[off] = 1;

  ld ans = 0;
  rep(i,0,n) {
    vector<ld> ndp(2*n+10);
    rep(j,1,sz(dp)-1) {
      ndp[j] = p[i]*dp[j-1] + (1-p[i])*dp[j+1];
    }
    swap(dp,ndp);
    ld cur = 0;
    rep(i,k,n+1) cur += dp[off+i];
    ans = max(ans, cur);
  }

  cout << setprecision(14) << fixed;
  cout << ans << endl;
}
