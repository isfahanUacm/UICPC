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
typedef long double ld;

// O(sqrt(n)log(n)), now with big integers.

ll n,m,k;
__int128 ans = 0;

__int128 f(__int128 x){
    if(x > n/k || (n - x*k > m*(k-1)) || x < 0)return -1;
    __int128 result = x*n - k * (x*(x-1))/2;
    __int128 n2 = n - x*k;
    __int128 k2 = n2/m + 1;
    __int128 x2 = n2 - m*(n2/m);
    result += x2*n2 - k2 * (x2*(x2-1))/2;
    __int128 n3 = n2 - x2*k2;
    __int128 k3 = k2-1;
    __int128 x3 = m-x2;
    result += x3*n3 - k3 * (x3*(x3-1))/2;
    ans = max(result, ans);
    return result;
}

void solve_nearby(ll x, ll radius){
    for(ll x2 = x-radius; x2 <= x+radius; x2++){
        f(x2);
    }
}

__int128 interpolate(ll x){
    __int128 y1 = f(x);
    __int128 y2 = f(x+1);
    __int128 y3 = f(x+2);
    __int128 Y1 = y2-y1;
    __int128 Y2 = y3-y2;
    __int128 a2 = Y2-Y1;
    __int128 b = Y1 - a2*x - a2/2;
    if(a2 == 0)return -1;
    return -b/a2;
}

ll next_x(ll x){
    ll l = x;
    ll r = n/k + 1;
    while(l < r-1){
        ll mid = (l+r)/2;
        if((n - mid*k) / m != (n - x*k) / m){
            r = mid;
        }
        else{
            l = mid;
        }
    }
    return r;
}

void solve(){
    ll x = max(ll(0),n/k - m + m/k);
    while(x <= n/k){
        solve_nearby(x,5);
        ll x2 = interpolate(x);
        solve_nearby(x2,5);
        x = next_x(x);
    }
    solve_nearby(x,5);
}

int main(){
    cin >> n >> m >> k;
    solve();
    string ans2 = "";
    while(ans > 0){
        ans2 += "0123456789"[ans%10];
        ans /= 10;
    }
    if(ans2.length() == 0){
        ans2 = "0";
    }
    reverse(all(ans2));
    cout << ans2 << "\n";
    return 0;
}
