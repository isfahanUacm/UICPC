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

vl factor(ll x){
    vl ans;
    for(ll c1 = 1; c1*c1 <= x; c1++){
        if(x%c1 == 0){
            ans.push_back(c1);
            if(c1*c1 != x)ans.push_back(x/c1);
        }
    }
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    ll n,m,a;
    cin >> n >> m >> a;
    if(a%n == 0 || a%m == 0){
        cout << "1\n";
        return 0;
    }
    vl f1 = factor(a);
    vl f2 = factor(n*m-a);
    trav(f, f1){
        if(f <= n && a/f <= m){
            cout << "2\n";
            return 0;
        }
    }
    trav(f, f2){
        if(f <= n && (n*m-a)/f <= m){
            cout << "2\n";
            return 0;
        }
    }
    cout << "3\n";

    return 0;
}
