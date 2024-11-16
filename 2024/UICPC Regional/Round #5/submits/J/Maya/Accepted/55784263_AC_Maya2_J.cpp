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
#define nl endl<<flush
#define arr array
#define pb push_back

void solve() {
    int n; cin >> n;
    auto qry = [&](string s) -> string {
        assert(s.size() == n);
        cout << "? " << s << nl;
        string res;
        cin >> res;
        return res;
    };
    vector<int> ans(n);
    auto kill = [&] () {
        cout << "! ";
        for (int i=0; i<n; i++) {
            cout << ans[i]+1 << ' ';
        }
        cout << nl;
    };

    auto get = [&] (int idx) -> string {
        string res;
        for (int i=0; i<4; i++) {
            res += ('a'+idx%26);
            idx /= 26;
        }
        reverse(res.begin(), res.end());
        return res;
    };
    vector<string> val(n);
    for (int i=0; i<n; i++) {
        val[i] = get(i);
    }
    array<string, 4> ret;
    for (int i=0; i<4; i++) {
        string s;
        for (int j=0; j<n; j++) {
            s += val[j][i];
        }
        ret[i] = qry(s);
    }
    vector<string> got(n);
    for (int i=0; i<n; i++) {
        string s;
        for (int j=0; j<4; j++) {
            s += ret[j][i];
        }
        got[i] = s;
    }
    map<string, int> idx;
    for (int i=0; i<n; i++) {
        idx[got[i]] = i;
    }
    for (int i=0; i<n; i++) {
        ans[i] = idx[val[i]];
    }
    kill();
}

int32_t main() {
    fastio
    int t = 1;
//cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

