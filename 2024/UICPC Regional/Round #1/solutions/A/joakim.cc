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
  cin>>n;

  int x = 0, y = 0;
  rep(i,0,n) {
    string s;
    cin>>s;
    for(char&c : s) if(c == '-') c = ' ';
    stringstream sin(s);
    int a, b;
    sin>>a>>b;
    if((a+b)%4 == 1 || (a+b)%4==2) swap(a,b);
    if(a < x || b < y || a > 11 || b > 11 || (a == 11 && b == 11)
        || ((x == 11 || y == 11) && (x != a || y != b))) {
      cout << "error " << i+1 << endl;
      exit(0);
    }

    x = a;
    y = b;
  }

  cout << "ok" << endl;
}
