#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {

    ll a,b;
    cin >> a >> b;

    __int128 m = __int128(a) * __int128(b);

    ll cnta = 0;

    while(a){
        a/=2;
        cnta++;
    }
    ll cntb = 0;

    while(b){
        b/=2;
        cntb++;
    }


    ll cntm = 0;
    while(m){
        m/=2;
        cntm++;
    }

    cnta--;
    cntb--;
    cntm--;

    if(cnta <= 32){
        cnta = 32;
    }
    else if (cnta <= 64){
        cnta = 64;
    }
    else{
        cnta = 128;
    }

    if(cntb <= 32){
        cntb = 32;
    }
    else if (cntb <= 64){
        cntb = 64;
    }
    else{
        cntb = 128;
    }

    if(cntm <= 32){
        cntm = 32;
    }
    else if (cntm <= 64){
        cntm = 64;
    }
    else{
        cntm = 128;
    }

    if(cnta > cntb){
        cout << cntm <<'\n' <<cntb << '\n' << cntm;
    }
    else{
        cout << cnta <<'\n' <<cntm << '\n' << cntm;
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