#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll na , nb , nc;
    cin >> na >> nb >> nc;
    ll a , b , c;
    cin >> a >> b >> c;
    ll x , y;
    cin >> x >> y;
    ll x1 = na - a;
    ll x2 = nc - c;
    if(x < x1 || y < x2){
        cout << "-1";
        return;
    }
    ll sum = 0;
    if(x1 > 0) {
        x -= x1;
        sum += x1;
    }
    if(x2 > 0) {
        y -= x2;
        sum += x2;
    }
    ll x3 = nb - b;
    if(((x + y) >= x3) && (x3 > 0)){
        sum += x3;
    }
    else{
        cout << "-1";
        return;
    }
    cout << sum;
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