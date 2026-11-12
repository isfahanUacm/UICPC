#include <bits/stdc++.h>
using namespace std;

#define ll long long

ll N = 1e5 + 5;
vector<vector<pair<ll , ll>>> avals(N);
vector<int> v(N);
vector<bool> visited(N, false);

void solve(){
    int q;
    cin >> q;
    int type;
    ll x;
    map<ll , ll> a;
    while(q--) {
        cin >> type >> x;
        if(type == 1) {
            for (auto &itr : avals[x]) {
                if (!visited[x]) {
                    ll val = x;
                    ll div = itr.first;
                    ll cntt = 0;
                    while (val % div == 0) {
                        val /= div;
                        cntt++;
                    }
                    itr.second = cntt;
                }

                auto tmp = a.find(itr.first);

                if (tmp != a.end()) {
                    tmp->second += itr.second;
                    if (tmp->second > 100) {
                        tmp->second = 100;
                    }
                }
                else {
                    a[itr.first] = itr.second;
                }
            }
            visited[x] = true;
        }
        else if (type == 2) {
            for (auto &itr : a) {
                if (x > 100) {
                    itr.second = 100;
                }
                else {
                    itr.second *= x;
                    if (itr.second > 100) {
                        itr.second = 100;
                    }
                }
            }
        }
        else {
            bool yes = true;
            auto m = avals[x];
            for (auto &itr : m) {
                if (!visited[x]) {
                    ll val = x;
                    ll div = itr.first;
                    ll cntt = 0;
                    while (val % div == 0) {
                        val /= div;
                        cntt++;
                    }
                    itr.second = cntt;
                }

                if (a[itr.first] < itr.second) {
                    cout << "No\n";
                    yes = false;
                    break;
                }
            }
            if (yes) {
                cout << "Yes\n";
            }
            visited[x] = true;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    v[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (v[i] == 0) {
            for (int j = i; j <= N; j += i) {
                v[j] = 1;
                avals[j].emplace_back(i , 1);
            }
        }
    }

    solve();

    return 0;
}