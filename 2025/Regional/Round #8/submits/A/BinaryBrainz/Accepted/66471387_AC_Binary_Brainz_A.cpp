#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll n , m;
    cin >> n >> m;
    while(n && m){
        set<ll> s;
        ll num;
        for (int i = 0; i < n; ++i) {
            cin >> num;
            if(num <= m){
                if((num % 7) != 0 && (num % 7) != 6){
                    s.insert(num);
                }
            }
        }
        ll ans = m;
        ans -= (int)s.size();
        if(m % 7 == 6){
            ans --;
        }
        ll extra = m / 7;
        ans -= (extra * 2);

        cout << ans << "\n";
        cin >> n >> m;
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