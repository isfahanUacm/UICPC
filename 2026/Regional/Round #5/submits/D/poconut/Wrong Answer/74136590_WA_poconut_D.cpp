#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
#ifdef LOCAL
#include "local.hpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

#define int long long
struct Q {
    ll a, b; 
    bool operator<(const Q &other) const {
        return a*other.b < other.a*b;
    }
    bool operator<=(const Q &other) const {
        return a*other.b <= other.a*b;
    }
    bool operator>=(const Q &other) const {
        return a*other.b >= other.a*b;
    }
    bool operator>(const Q &other) const {
        return a*other.b > other.a*b;
    }
    friend string to_string(const Q &x) {
        return to_string(x.a) + "/" + to_string(x.b);
    }
    friend ostream& operator <<(ostream& o, const Q& x) {
        return o << to_string(x);
    }
};

void solve([[ maybe_unused ]] uint32_t tc) {
    // a b c d (a-b)k + (c-d)l >= 0 -> (a-b)/(d-c) >= l/k
    // a b c d (a-b)k + (d-c)l >= 0 -> (a-b)/(c-d) >= l/k
    // a b c d (b-a)k + (c-d)l >= 0 -> (b-a)/(d-c) >= l/k
    // a b c d (b-a)k + (d-c)l >= 0 -> (b-a)/(c-d) >= l/k

    int n, q; cin >> n >> q;
    vector<array<int, 4>> A(n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<4; j++) {
            cin >> A[i][j];
        }
    }
    if (n == 1) {
        auto [a, b, c, d] = A[0];
        while (q--) {
            ll k, l; cin >> k >> l;
            cout << ((ll)abs(a-b)*k + (ll)abs(c-d)*l) << nl;
        }
        return;
    }
    array<vector<pair<Q, pair<ll, ll>>>, 4> v{};
    for (int i=0; i<4; i++) {
        for (int j=0; j<n; j++) {
            auto [a, b, c, d] = A[j];
            if (i == 0) {
                v[i].push_back({Q{a-b, d-c}, {a-b, c-d}});
            } else if (i == 1) {
                v[i].push_back({Q{a-b, c-d}, {a-b, d-c}});
            } else if (i == 2) {
                v[i].push_back({Q{b-a, d-c}, {b-a, c-d}});
            } else {
                v[i].push_back({Q{b-a, c-d}, {b-a, d-c}});
            }
        }
    }
    for (int i=0; i<4; i++) {
        sort(v[i].begin(), v[i].end());
        for (int j=0; j<n-1; j++) {
            assert(v[i][j].first <= v[i][j+1].first);
        }
    }
    array<vector<ll>, 4> pre_k, pre_l;
    for (int j=0; j<4; j++) {
        pre_k[j].assign(n+1, 0);
        pre_l[j].assign(n+1, 0);
        for (int i=0; i<n; i++) {
            pre_k[j][i+1] = pre_k[j][i] + v[j][i].second.first;
            pre_l[j][i+1] = pre_l[j][i] + v[j][i].second.second;
        }
    }
    // (-6, -1) <= (1, 1) <= (5, -3) ??
    dbg(v);
    dbg(pre_k, pre_l);
    while (q--) {
        int l, k; cin >> k >> l;
        Q t{l, k};
        array<ll, 4> res{};
        for (int i=0; i<4; i++) {
            if (v[i][0].first >= t && v[i].back().first >= t) {
                res[i] = pre_k[i][n] * k + pre_l[i][n] * l;
            } else if (v[i][0].first < t) {
                int lo = 0, hi = n;
                while (hi - lo > 1) {
                    int md = lo + (hi - lo) / 2;
                    if (v[i][md].first >= t) {
                        hi = md;
                    } else {
                        lo = md;
                    }
                }
                res[i] = (pre_k[i][n] - pre_k[i][hi]) * k +
                    (pre_l[i][n] - pre_l[i][hi]) * l;
            } else if (v[i].back().first < t) {
                int lo = -1, hi = n-1;
                while (hi - lo > 1) {
                    int md = lo + (hi - lo) / 2;
                    if (v[i][md].first >= t) {
                        lo = md;
                    } else {
                        hi = md;
                    }
                }
                res[i] = pre_k[i][lo+1] * k + pre_l[i][lo+1] * l;
            }
        }
        dbg(res);
        cout << *max_element(res.begin(), res.end()) << nl;
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


