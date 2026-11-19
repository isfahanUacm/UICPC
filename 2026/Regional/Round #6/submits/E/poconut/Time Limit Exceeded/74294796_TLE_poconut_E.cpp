#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] uint32_t tc) {
    int n, m; cin >> n >> m;
    vector<string> a(n), b(n);
    using S = array<int, 4>;
    S st;
    for (int i=0; i<n; i++) {
        cin >> a[i];
        for (int j=0; j<m; j++) {
            if (a[i][j] == 'S') {
                st[0] = i, st[1] = j;
            }
        }
    }
    for (int i=0; i<n; i++) {
        cin >> b[i];
        for (int j=0; j<m; j++) {
            if (b[i][j] == 'S') {
                st[2] = i, st[3] = j;
            }
        }
    }
    using T = pair<int, S>;
    map<S, int> dis;
    priority_queue<T, vector<T>, greater<T>> pq;
    pq.push({0, st});
    dis[st] = 0;
    array<int, 4> dx = {-1, 1, 0, 0}, dy = {0, 0, -1, 1};
    auto ok = [&] (int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    auto done = [&] (S x) {
        auto [xa, ya, xb, yb] = x;
        return b[xb][yb] == 'D';
    };
        
    const int inf = 1e9+5;
    int ans = inf;
    while (!pq.empty()) {
        int d = pq.top().first;
        S cur = pq.top().second;
        auto [xa, ya, xb, yb] = cur;

        pq.pop();
        if (dis.contains(cur) && d != dis[cur]) {
            continue;
        }

        for (int i=0; i<4; i++) {
            int xb1 = xb+dx[i], yb1 = yb+dy[i];
            int xa1 = xa+dx[i], ya1 = ya+dy[i];
            if (!ok(xb1, yb1) || b[xb1][yb1] == 'X') {
                xb1 = xb;
                yb1 = yb;
            }
            S s = {xa1, ya1, xb1, yb1};
            if (ok(xa1, ya1) &&
                    a[xa1][ya1] != 'X' &&
                    (!dis.contains(s) || dis[s] > d+1)) {
                dis[s] = d+1;
                pq.push({d+1, s});
                if (done(s)) {
                    ans = min(ans, d+1);
                }
            }
        }
    }
    if (ans < inf) {
        cout << ans << nl;
    } else {
        cout << -1 << nl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    
    #ifdef TESTCASE
    cin >> t;
    #endif
    for (int i=1; i<=t; i++) {
        Solve(i);
    }
    return 0;
}