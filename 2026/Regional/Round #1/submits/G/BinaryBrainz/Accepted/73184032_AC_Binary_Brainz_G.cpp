#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll n , q , k;
    cin >> n >> q >> k;
    ll c = 5e8 , j = 1e8 , p = 2e7;
    ll ml = 2e7;
    string type;
    cin >> type;
    bool ok1 = false , ok2 = false;
    ll sum = n * k;
    if(sum > ml){
        ok1 = true;
    }
    sum = (n * (2 * q))+( n* (5 * k));
    if(type == "java"){
        if(sum > j){
            ok2 = true;
        }
    }
    else if(type == "cpp"){
        if(sum > c){
            ok2 = true;
        }
    }
    else{
        if(sum > p){
            ok2 = true;
        }
    }
    if(!ok1 && !ok2){
        cout << "OK";
    }
    else if(ok1 && ok2){
        cout << "TL and ML";
    }
    else if(ok1){
        cout << "ML";
    }
    else{
        cout << "TL";
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