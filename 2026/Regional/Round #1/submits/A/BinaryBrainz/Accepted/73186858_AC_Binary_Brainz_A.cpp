#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    ll n , p , q;
    cin >> n >> p >> q;
    vector<vll> acc(n , vll(p , -1));
    vector<array<ll , 3>> ans(n);
    for (int i = 0; i < n; ++i) {
        ans[i][2] = i;
        ans[i][1] = 0;
        ans[i][0] = 0;
    }
    vector<vll> fail(n , vll(p));
    for (int i = 0; i < q; ++i) {
        ll time, id, que, v;
        cin >> time >> id >> que >> v;
        id--;
        que--;
        if (acc[id][que] == -1) {
            if (v == 1) {
                acc[id][que] = time;
                ans[id][0]--;
            }
            else {
                fail[id][que]++;
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        ll T = 0;
        for (int j = 0; j < p; ++j) {
            if(acc[i][j] != -1){
                T += acc[i][j] + 20 * fail[i][j];
            }
        }
        ans[i][1] = T;
    }
    std::sort(ans.begin(), ans.end());
    int rate = 1;
    for (int i = 0; i < n; ++i) {
        if(i == 0){
            cout << i + 1 << " " << ans[i][2] + 1 << " " << (ans[i][0] * -1) << " " << ans[i][1];
        }
        else{
            if((ans[i][1] == ans[i - 1][1]) && (ans[i][0] == ans[i][0])){
                cout << rate << " " << ans[i][2] + 1 << " " << (ans[i][0] * -1) << " " << ans[i][1];
            }
            else{
                rate = i + 1;
                cout << rate << " " << ans[i][2] + 1 << " " << (ans[i][0] * -1) << " " << ans[i][1];
            }
        }
        cout << "\n";
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