#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>
#define ll long long



void solve() {

    ll n;
    cin >> n;

    vector<pair<ll,int>> c(n);
    vector<pair<ll,int>> b(n);
    ll tmp;
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        b[i] = make_pair(tmp,i + 1);
    }
    for (int i = 0 ; i < n ; i++) {
        cin >> tmp;
        c[i] = make_pair(tmp,i + 1);
    }

    sort(begin(b), end(b));
    sort(c.begin(), c.end(),[](auto &a, auto &b) {
        return a.first > b.first;
    });

    vector<vector<ll>> p(n,vector<ll>(n));

    ll crnt_board = 0;
    ll crnt_color = 0;

    auto idx = [](pair<ll,int> x) {
        return x.second - 1;
    };

    while (crnt_board < n && crnt_color < n) {

        if (b[crnt_board].first > c[crnt_color].first) {
            p[idx(b[crnt_board])][idx(c[crnt_color])] = c[crnt_color].first;
            b[crnt_board].first -= c[crnt_color].first;
            crnt_color++;
        }
        else if (b[crnt_board].first < c[crnt_color].first) {
            p[idx(b[crnt_board])][idx(c[crnt_color])] = b[crnt_board].first;
            c[crnt_color].first -= b[crnt_board].first;
            crnt_board++;
        }
        else {
            p[idx(b[crnt_board])][idx(c[crnt_color])] = c[crnt_color].first;
            crnt_color++;
            crnt_board++;
        }
    }
    for (int i = 0; i < n ; i++) {
        for (int j = 0; j < n ;j++) {
            cout << p[i][j] << " ";
        }
        cout << '\n';
    }

    for (int i = 0; i < n ; i++) {
        cout << b[i].second << " ";
    }

}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        solve();
        if (t)
            cout << endl;
    }

    return 0;
}