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
        string ans = s;
        bool flag = false;
        for (int i = 1; i < n; ++i) {
            if(s[i] == s[0]){
                int j = 1;
                while((i + j) < n && s[i + j] == s[j]){
                    j++;
                }
                if((i + j) == n){
                    for (int k = n - i; k < n; ++k) {
                        ans += s[k];
                    }
                    cout << ans << "\n";
                    cin >> n;
                    flag = true;
                    break;
                }
            }
        }
        if(flag){
            continue;
        }
        ans += s;
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