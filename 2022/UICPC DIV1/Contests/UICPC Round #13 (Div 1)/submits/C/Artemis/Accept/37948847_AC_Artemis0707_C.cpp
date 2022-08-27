#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll MAX = 30;
const ll t = 1e6+10;
ll dist[MAX][t];
set<pair<ll, pair<ll, ll>>> q;
vector<pair<ll, ll>> all;
vector<string> str;
map<string, ll> bit;
vector<ll> bin;

ll cd(pair<ll, ll> a, pair<ll, ll> b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

void dijkstra(int start) {
    dist[start][0] = 0;
    q.insert({0, {start, 0}});
    while (!q.empty()) {
        auto u = q.begin()->second;
        q.erase(q.begin());
        for (int i = 1; i < all.size(); i++) {
            if (i == u.first)
                continue;
            ll mask = u.second;
            mask |= bin[i];
            if (dist[i][mask] > dist[u.first][u.second] + cd(all[i], all[u.first])) {
                q.erase({dist[i][mask], {i, mask}});
                dist[i][mask] = dist[u.first][u.second] + cd(all[i], all[u.first]);
                q.insert({dist[i][mask], {i, mask}});
            }
        }
    }
}

int main() {
    ll n;
    cin >> n;
    all.emplace_back(0, 0);
    bin.push_back(0);

    for (int i = 0; i < MAX; ++i) {
        for (int j = 0; j < t; ++j) {
            dist[i][j] = LONG_LONG_MAX / 10;
        }
    }
    
    for (int i = 0; i < n; ++i) {
        ll x, y;
        string temp;
        cin >> x >> y >> temp;
        all.emplace_back(x, y);
        str.push_back(temp);

        int s = bit.size();
        if(bit.count(temp) == 0) {
            bit[temp] = s;
        }
        bin.push_back(1 << (bit[temp]));
    }
    dijkstra(0);

    ll ans = LONG_LONG_MAX / 10;
    for (int i = 1; i <= n; ++i) {
        int val = pow(2, bit.size()) - 1;
        ans = min(ans, dist[i][val] + cd(all[0], all[i]));
    }

    cout << ans << endl;
}
