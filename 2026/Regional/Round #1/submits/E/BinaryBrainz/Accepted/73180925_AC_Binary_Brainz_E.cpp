#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {

    ll n, p;
    cin >> n >> p;

    vector<vector<pair<bool,int>>> v(n,vector<pair<bool,int>>(p));

    for(int i =0 ; i < n ; i++){
        for(int j = 0 ; j < p ; j ++){
            ll at;
            char s;
            cin >> s >> at;
            v[i][j].first = (s == '+');
            v[i][j].second += at;
        }
    }

    for(int j =0 ; j < p ; j++){
        ll S= 0,T= 0,F = 0;
        for(int i = 0 ; i < n ; i ++) {
            if(v[i][j].first){
                S++;
            }
            if(v[i][j].second > 0 || v[i][j].first){
                T++;
            }
            F += v[i][j].second;
        }
        cout << S <<' ' << T <<' ' << F << '\n';
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