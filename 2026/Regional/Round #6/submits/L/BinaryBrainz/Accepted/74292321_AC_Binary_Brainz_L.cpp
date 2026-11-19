#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define MOD 1006903069

void solve() {

    ll n ;
    cin >> n;

    vector<vector<pair<ll,ll>>> a(n);
    vector<vector<pair<ll,ll>>> b(n);

    ll ka;
    cin >> ka;
    for (int m =0 ; m < ka; m++) {
        ll i, j, x;
        cin >> i >> j >> x;
        i--;
        j--;

        a[i].push_back({j,x});
    }


    ll kb;
    cin >> kb;

    for (int m =0 ; m < kb; m++) {
        ll i, j, x;
        cin >> i >> j >> x;
        i--;
        j--;
        b[j].push_back({i,x});
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        ll ai = 0, bi = 0;
        if (a[i].size() == 0 || b[i].size() == 0) {
            continue;
        }

        sort(a[i].begin(), a[i].end());
        sort(b[i].begin(), b[i].end());

        ll an = a[i].size();
        ll bn = b[i].size();

        while (ai < an) {
            while (bi < bn && b[i][bi].first < a[i][ai].first) {
                bi++;
            }
            if (bi < bn) {
                if (b[i][bi].first == a[i][ai].first)
                    ans = (ans + b[i][bi].second * a[i][ai].second) % MOD;
            }
            else break;

            ai++;
        }
    }

    cout << ans;
}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();

    return 0;
}