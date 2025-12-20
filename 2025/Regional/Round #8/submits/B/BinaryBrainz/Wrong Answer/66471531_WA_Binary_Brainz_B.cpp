#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n;
    cin >> n;
    while(n){
        string s;
        cin >> s;
        int cnt = 0;
        for (int i = 0; i < n - 1; ++i) {
            if(s[i] == s[i + 1]){
                cnt++;
            }
        }
        if(cnt == n - 1){
            s += s[0];
            cout << s << "\n";
            cin >> n;
            continue;
        }
        cnt = 0;
        for (int i = 0; i < n / 2; ++i) {
            if(s[i] == s[n - 1 - i]){
                cnt++;
            }
            else{
                break;
            }
        }
        string ans = s;
        for (int i = cnt; i < n; ++i) {
            ans += s[i];
        }
        cout << ans << "\n";
        cin >> n;
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