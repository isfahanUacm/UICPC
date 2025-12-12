#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int q;
    cin >> q;
    vector<vi> v;
    int type;
    while(q--){
        cin >> type;
        if(type == 1){
            vi temp;
            v.push_back(temp);
        }
        else if(type == 2){
            int i , x;
            cin >> i >> x;
            v[i - 1].push_back(x);
        }
        else{
            int i , j;
            cin >> i >> j;
            int size = v[i - 1].size();
            cout << v[i - 1][j - 1] << '\n';
        }
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