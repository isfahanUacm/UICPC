#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    int n , k;
    cin >> n >> k;
    int num;
    set<int> a;
    for (int i = 0; i < n; ++i) {
        cin >> num;
        a.insert(num);
    }
    cout << min((int)a.size() , k);
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