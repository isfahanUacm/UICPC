#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>

void solve() {
    ll l , k , q;
    cin >> l >> q >> k;
    string s;
    cin >> s;
    ll ans = k * 5 + q * 2;
    ans *= l;
    bool ok1 = true , ok2 = true;
    if(s[0] == 'c'){
        if(ans > 5e8){
            ok1 = false;
        }
        if(k * l > 2e7){
            ok2 = false;
        }
    }
    else if(s[0] == 'j'){
        if(ans > 1e8){
            ok1 = false;
        }
        if(k * l > 2e7){
            ok2 = false;
        }
    }
    else{
        if(ans > 2e7){
            ok1 = false;
        }
        if(k * l > 2e7){
            ok2 = false;
        }
    }
    if(ok1 && ok2){
        cout << "OK";
    }
    else if(!ok1 && ok2){
        cout << "TL";
    }
    else if(ok1 && !ok2){
        cout << "ML";
    }
    else{
        cout << "TL and ML";
    }
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