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
    ll n;
    cin >> n;
    
    ll best = 1e18;
    ll xa = -1;
    ll ya = -1;

    for(ll x = 0; x <= n; x++){
        ll y = ll(sqrt(n*n - x*x));
        while(y*y + x*x <= n*n){
            y++;
        }
        if(y*y + x*x < best || (y*y + x*x == best && rand()%2 == 0)){
            xa = x;
            ya = y;
            best = y*y + x*x;
        }
    }

    cout << xa << " " << -ya << "\n";

    return 0;
}
