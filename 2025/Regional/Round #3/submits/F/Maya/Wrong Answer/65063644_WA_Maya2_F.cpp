#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

struct DSU {
    int n;
    vector<int> par, sz;
    DSU(int _n) {
        n = _n;
        par.resize(n);
        iota(par.begin(), par.end(), 0);
        sz.assign(n, 1);
    }
    int find(int x) {
        if (par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return 0;
        if (x < y) swap(x, y);
        sz[x] += sz[y];
        par[y] = x;
        return 1;
    }
};
vector<string> split(const string &s, const char ch = ' ') {
    int n = (int)s.size();
    vector<string> sp;

    string tmp;
    for (int i = 0; i < n; i++) {
        if (s[i] != ch) {
            tmp += s[i];
        }
        else if (tmp != "") {
            sp.push_back(tmp);
            tmp = "";
        }
    }
    if (tmp != "") {
        sp.push_back(tmp);
    }
    return sp;
}
void solve(int tc) {
    int n; cin >> n;
    cin.ignore();

    map<string, int> id;
    set<string> s;
    int x = 0;
    vector<array<int,2>> v;

    for (int i=0; i<n; i++) {
        string t;
        getline(cin, t);

        auto vv = split(t);
        string a = vv[0].substr(0, (int)vv[0].size()-1);
        string b = vv.back();

        if (!s.count(a)) {
            id[a] = x++;
            s.insert(a);
        }
        if (!s.count(b)) {
            id[b] = x++;
            s.insert(b);
        }
        v.push_back(array<int, 2>{id[a], id[b]});
    }

    dbg(x);
    auto dsu = DSU(x);
    for (auto [u, t]: v) {
        dsu.merge(u, t);
    }
    cout << (dsu.sz[dsu.find(0)] == x ?"possible": "impossible") << nl;
    /*
    */
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


