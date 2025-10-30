#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

vector<string> split(const string &s, const char ch = ' ') {
    int n = s.size();
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

void solve() {
    int n;
    cin >> n;

    string foo;
    getline(cin, foo);


    vector<pair<string, double>> a(n);
    double num = 100;
    for (int i = 0; i < n; i++) {
        string s;
        getline(cin, s);
        auto vs = split(s);
        if (vs.size() == 1) {
            a[i] = {vs[0], -1};
        } else {
            a[i] = {vs[0], stod(vs[1])};
            num -= a[i].second;
        }
    }
    dbg(a);

    if (n == 1) {
        cout << a[0].first << ' ' << 100 << ' ' << 100 << '\n';
        return;
    }

    vector<double> mn(n), mx(n, num);
    double mnn = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (a[i].second == -1) {
            mn[i] = mnn;
        } else {
            mnn = a[i].second;
        }
    }
    if (mnn == 0) {
        for (int i = 0; i < n; i++) {
            if (a[i].second == -1) {
                mn[i] = double(100) / n;
                break;
            }
        }
    }

    double mxx = num;
    int val = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].second == -1) {
            val++;
            mx[i] = mxx / val;
        } else {
            mxx -= val * a[i].second;
            val = 0;
        }
    }

    cout << fixed << setprecision(6);
    for (int i = 0; i < n; i++) {
        if (a[i].second == -1)  {
            cout << a[i].first << ' ' << mn[i] << ' ' << mx[i] << '\n';
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
