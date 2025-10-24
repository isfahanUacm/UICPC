#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>



void solve() {
    ll n = 9223372036854775807;
    ll a , b;
    cin >> a >> b;
    __int128 c = __int128(a) * __int128(b);
    int ta , tb , tc;
    if(a <= 2147483647){
        ta = 32;
    }
    else if(a <= n){
        ta = 64;
    }
    else{
        ta = 128;
    }
    if(b <= 2147483647){
        tb = 32;
    }
    else if(b <= n){
        tb = 64;
    }
    else{
        tb = 128;
    }
    if(c <= 2147483647){
        tc = 32;
    }
    else if(c <= n){
        tc = 64;
    }
    else{
        tc = 128;
    }
    if(tc != ta && tc != tb){
        if(ta > tb){
            ta = tc;
        }
        else{
            tb = tc;
        }
    }
    cout << ta << "\n";
    cout << tb << "\n";
    cout << tc << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}