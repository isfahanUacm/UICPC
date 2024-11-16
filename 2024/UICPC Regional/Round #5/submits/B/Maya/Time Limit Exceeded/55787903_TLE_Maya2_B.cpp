#include<bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

vector<ll> goods;
vector<int> digit(18);
void bt(int idx) {
    if (idx == 18) {
        ll res = 0;
        for (int i=0; i<18; i++) {
            res = 10*res+digit[i];
        }
        goods.pb(res);
        return;
    }
    int beg = (idx == 0? 0 : digit[idx-1]);
    for (int i=beg; i<=9; i++) {
        digit[idx] = i;
        bt(idx+1);
        digit[idx] = 0;
    }
}
void prec() {
    bt(0);
    sort(goods.begin(), goods.end());
}
void solve() {
    ll n; cin >> n;


    int idx = upper_bound(goods.begin(), goods.end(), n)-goods.begin()-1;
    set<ll> s;
    auto calc = [&] (ll t) -> ll {
        ll res = 1;
        while (t) {
            res *= t%10;
            t /= 10;
        }
        return res;
    };
    for (int i=0; i<=idx; i++) {
        s.insert(calc(goods[i]));
    }
    cout << s.size()+(n>=10) << nl;
}

int32_t main() {
    prec();
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

