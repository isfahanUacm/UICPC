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
  string s;
  cin >> n >> s;
  int have = 0, ans = 0;
  for(char c : s) {
    if(c == '1') have = 3;
    if(have > 0) ++ans;
    --have;
  }
  cout << ans << endl;
}
