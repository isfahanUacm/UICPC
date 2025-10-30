#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

#define double long double

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

    auto ok1 = [&](double x, int ind) {
        double sum = x, mx0 = x, mx1 = 100;
        for (int i = ind + 1; i < n; i++) {
            if (a[i].second == -1) {
                sum += mx0;
            } else {
                mx0 = a[i].second;
                sum += a[i].second;
            }
        }
        for (int i = 0; i < ind; i++) {
            if (a[i].second == -1) {
                sum += mx1;
            } else {
                mx1 = a[i].second;
                sum += a[i].second;
            }
        }
        return sum >= 100.0;
    };

    auto ok2 = [&](double x, int ind) {
        double sum = x, mn0 = 0, mn1 = x;
        for (int i = n - 1; i > ind; i--) {
            if (a[i].second == -1) {
                sum += mn0;
            } else {
                mn0 = a[i].second;
                sum += a[i].second;
            }
        }
        for (int i = ind - 1; i >= 0; i--) {
            if (a[i].second == -1) {
                sum += mn1;
            } else {
                mn1 = a[i].second;
                sum += a[i].second;
            }
        }
        return sum <= 100.0;
    };


    vector<double> mn(n), mx(n, num);
    for (int i = 0; i < n; i++) {
        if (a[i].second == -1) {
            double mnn = 0, mxx = num;
            for (int j = i - 1; j >= 0; j--) {
                if (a[j].second != -1) {
                    mxx = max(num, a[j].second);
                    break;
                }
            }
            for (int j = i + 1; j < n; j++) {
                if (a[j].second != -1) {
                    mnn = a[j].second;
                    break;
                }
            }

            const double eps = 1e-8;
            double lo = mnn, hi = mxx;
            while (hi - lo > eps) {
                double mid = lo + (hi - lo) / 2;
                if (ok1(mid, i)) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            mn[i] = hi;

            lo = mnn, hi = mxx;
            while (hi - lo > eps) {
                double mid = lo + (hi - lo) / 2;
                if (ok2(mid, i)) {
                    lo = mid;
                } else {
                    hi = mid;
                }
            }
            mx[i] = lo;
        }
    }


    cout << fixed << setprecision(7);
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
