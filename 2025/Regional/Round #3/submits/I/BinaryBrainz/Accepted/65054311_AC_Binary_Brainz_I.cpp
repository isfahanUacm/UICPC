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
    vector<string> ans;
    string pre;
    for (int j = 0; j < n; ++j) {
        int m;
        cin >> m;
        vector<string> a(m);
        for (int i = 0; i < m; ++i) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        if(j == 0){
            ans.push_back(a[0]);
            pre = a[0];
        }
        else{
            bool flag = false;
            for (auto x : a) {
                if(x >= pre){
                    ans.push_back(x);
                    pre = x;
                    flag = true;
                    break;
                }
            }
            if(!flag){
                cout << "impossible";
                return;
            }
        }
    }
    for(auto x : ans){
        cout << x << "\n";
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