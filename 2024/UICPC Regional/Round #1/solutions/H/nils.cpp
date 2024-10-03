#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<ll> vl;

int main() {
    int n;
    cin >> n;
    vl H(n);
    vl LEFT(n, 0), RIGHT(n, 0);
    rep(c1,0,n){
        cin >> H[c1];
    }
    for(int c1 = 1; c1 < n; c1++){
        if(H[c1] >= H[c1-1]){
            LEFT[c1] = 1 + LEFT[c1-1];
        }
    }
    for(int c1 = n-2; c1 >= 0; c1--){
        if(H[c1] >= H[c1+1]){
            RIGHT[c1] = 1 + RIGHT[c1+1];
        }
    }
    ll ans = 0;
    for(int c1 = 0; c1 < n; c1++){
        ll h = min(H[c1]-H[c1-LEFT[c1]], H[c1]-H[c1+RIGHT[c1]]);
        ans = max(ans, h);
    }

    cout << ans << "\n";

    return 0;
}
