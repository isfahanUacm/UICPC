#include <bits/stdc++.h>
using namespace std;
const int MOD = 1000000007; const int MOD1 = 998244353; const int INF = 2e9; const long double PI = 3.141592653589793238462;
using str = string; using ld = long double; using ll = long long; using vi = vector<int>; using vl = vector<ll>; using pi = pair<int, int>; using pl = pair<ll, ll>; using vpi = vector<pi>; using vpl = vector<pl>; template<class T> using pq = priority_queue<T>; template<class T> using pqg = priority_queue<T, vector<T>, greater<T>>; template<typename T, typename T1>T amax(T& a, T1 b) {if(b>a)a = b;return a;} template<typename T, typename T1>T amin(T& a, T1 b) {if(b<a)a = b;return a;} template<class T> int sz(const T& container) {return (int)container.size();} template<class T, int s> using arr = array<T, s>;
#define pb push_back
#define pf push_front
#define ppb pop_back
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define lb lower_bound
#define ub upper_bound
#define tostr to_string
#ifdef LOCAL
#include "/home/pouya/debug.cpp"
#else
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define dbg(...)
#define adbg(...)
#define LINE
#define TIME
#define nl "\n"
#endif
/*******************************************************************************/

const int N = 100+10;
int a[N][N], n, m;
ll dp[N][N];
char ss[N][N];
void solve() {
  cin >> n >> m;
  bool zero = false;
  arr<int, 2> pos;
  for (int i=0; i<n; i++) for (int j=0; j<m; j++) {
    cin >> a[i][j];
    if (a[i][j] == 0) zero = true, pos = {i, j};
  }

  vector<char> s2, s5;
  auto dpgrid = [&] (int x) {
    memset(dp, 0, N*N);
    for (int i=0; i<n; i++) {
      for (int j=0; j<m; j++) {
        int c = 0;
        int t = a[i][j];
        while (t && t%x==0) t/=x, c++;
        if (t == 0) dp[i][j] = INF;
        else dp[i][j] = c;
        if (i == 0 && j == 0) continue;
        if (j-1<0) {
          ss[i][j] = 'D';
          dp[i][j] += dp[i-1][j];
        } else if (i-1<0) {
          ss[i][j] = 'R';
          dp[i][j] += dp[i][j-1];
        } else {
          if (dp[i-1][j] > dp[i][j-1]) {
            ss[i][j] = 'R';
            dp[i][j] += dp[i][j-1];
          } else {
            ss[i][j] = 'D';
            dp[i][j] += dp[i-1][j];
          }
        }
      }
    }
  };

  auto gen = [&] (vector<char>& s) {
    int i = n-1, j = m-1;
    while (!(i==0 && j==0)) {
      s.pb(ss[i][j]);
      if (ss[i][j] == 'D') {
        i--;
      } else {
        j--;
      }
    }
  };

  dpgrid(2);
  ll ans2 = dp[n-1][m-1];
  gen(s2);

  dpgrid(3);
  ll ans5 = dp[n-1][m-1];
  gen(s5);

  if (min(ans2, ans5) > 1 && zero) {
    cout << 1 << nl;
    for (int i=0; i<pos[0]; i++) cout << 'D';
    for (int i=0; i<pos[1]; i++) cout << 'R';
    for (int i=0; i<n-pos[0]-1; i++) cout << 'D';
    for (int i=0; i<n-pos[1]-1; i++) cout << 'R';
    cout << nl;
    return;
  }
  if (ans2 < ans5) {
    cout << ans2 << nl;
    /*
    for (int i=2*n-3; ~i; i--) {
      cout << s2[i];
    }
    cout << nl;
    */
  } else {
    cout << ans5 << nl;
    /*
    for (int i=2*n-3; ~i; i--) {
      cout << s5[i];
    }
    cout << nl;
    */
  }
}

int main() {
  fastio();
	int T = 1;
	cin >> T;
	while (T--) {
    solve();
    LINE
	}
  TIME
  return 0;
}
