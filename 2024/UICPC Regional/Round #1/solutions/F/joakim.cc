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


vi pi(const string& s) {
  vi p(sz(s));
  rep(i,1,sz(s)) {
    int g = p[i-1];
    while (g && s[i] != s[g]) g = p[g-1];
    p[i] = g + (s[i] == s[g]);
  }
  return p;
}

vi match(const string& s, const string& pat) {
  vi p = pi(pat + '\0' + s), res;
  rep(i,sz(p)-sz(s),sz(p))
    if (p[i] == sz(pat)) res.push_back(i - 2 * sz(pat));
  return res;
}

void bad(string s = "NONE") {
  cout << s << endl;
  exit(0);
}

int main() {
  cin.tie(0)->sync_with_stdio(0);
  cin.exceptions(cin.failbit);
  int n;
  cin >> n;

  if(n == 2) {
    string a, b;
    cin>>a>>a>>b;
    if(sz(a) != sz(b)) bad();
    vi q = match(a+a,b);
    debug(q);
    string A = "", B = "";
    for(int off : q) {
      if(off == 0 || off == sz(a)) continue;
      if(A != "") bad("MANY");
      A = a.substr(0,off);
      B = a.substr(off,sz(a));
    }
    if(A == "") bad();
    cout << "UNIQUE" << endl;
    cout << A << endl; 
    cout << B << endl; 
    exit(0);
  }

  vector<vector<string>> v(n,vector<string>(n));
  rep(i,0,n) rep(j,0,n) cin >> v[i][j];

  int len = 0;
  rep(i,0,n) rep(j,0,n) if(i != j){
    if(sz(v[i][j]) != sz(v[j][i])) bad();
    if(sz(v[i][j]) == 1) bad();
    len += sz(v[i][j]);
  }

  if(len % (2*(n-1)) != 0) bad();
  len /= 2*(n-1);

  vector<string> ans(n);
  rep(i,0,n) {
    int we = 0;
    rep(j,0,n) we += sz(v[i][j]);
    we -= len+1;
    if(we % (n-2) != 0) bad();
    we /= (n-2);
    if(we <= 0) bad();
    ans[i] = v[i][i ? 0 : 1].substr(0,we);
  }

  rep(i,0,n) rep(j,0,n) if(i != j) {
    if(ans[i] + ans[j] != v[i][j]) bad();
  }

  cout << "UNIQUE" << endl;
  rep(i,0,n) cout << ans[i] << endl;
}
