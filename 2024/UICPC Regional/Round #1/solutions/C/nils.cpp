#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    int coffee = 0;
    rep(c1,0,n){
        if(s[c1] == '1')coffee = 3;
        ans += (coffee > 0);
        coffee--;
    }
    cout << ans << "\n";
    return 0;
}
