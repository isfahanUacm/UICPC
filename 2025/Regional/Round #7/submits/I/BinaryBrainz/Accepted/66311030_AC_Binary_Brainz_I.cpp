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
    cin >> m >> n;
    vector<string> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        for (int j = 0; j < m; ++j) {
            if(a[i][j] >= 'a' && a[i][j] <= 'z'){
                a[i][j] -= 32;
            }
        }
    }
    ll ans = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(a[i][j] == 'U'){
                if(i > 1){
                    if(a[i - 1][j] == 'V' && a[i - 2][j] == 'A'){
                        ans++;
                    }
                    if(j > 1){
                        if(a[i - 1][j - 1] == 'V' && a[i - 2][j - 2] == 'A'){
                            ans++;
                        }
                    }
                    if(j + 2 < m){
                        if(a[i - 1][j + 1] == 'V' && a[i - 2][j + 2] == 'A'){
                            ans++;
                        }
                    }
                }
                if(i + 2 < n){
                    if(a[i + 1][j] == 'V' && a[i + 2][j] == 'A'){
                        ans++;
                    }
                    if(j + 2 < m){
                        if(a[i + 1][j + 1] == 'V' && a[i + 2][j + 2] == 'A'){
                            ans++;
                        }
                    }
                    if(j > 1){
                        if(a[i + 1][j - 1] == 'V' && a[i + 2][j - 2] == 'A'){
                            ans++;
                        }
                    }
                }
                if(j > 1){
                    if(a[i][j - 1] == 'V' && a[i][j - 2] == 'A'){
                        ans++;
                    }
                }
                if(j + 2 < m){
                    if(a[i][j + 1] == 'V' && a[i][j + 2] == 'A'){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans;
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