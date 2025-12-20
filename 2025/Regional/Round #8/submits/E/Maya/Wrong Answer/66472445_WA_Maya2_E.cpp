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

void solve(int tc) {
    while (1) {
        int n, m; cin >> n >> m;
        dbg(n, m);
        if (n == 0 && m == 0) {
            return;
        }
        vector<string> a(n);
        for (int i=0; i<n; i++) {
            cin >> a[i];
        }
        bool bad = 0;

        string s1 = a[0], s2 = a[0];
        for (int j=0; j<m; j++) {
            if (s1[j] == '.') {
                s2[j] = '#';
            } else {
                s2[j] = '.';
            }
        }
        for (int i=0; i<n; i++) {
            if (a[i] != s1 && a[i] != s2) {
                bad = 1;
                break;
            }
        }
        if (bad) {
            cout << -1 << nl;
            continue;
        }

        int dis = -1;
        for (int i=0; i<n; i++) {
            int c = 0;
            vector<int> v;
            for (int j=0; j<m; j++) {
                c++;
                if (j+1==m || a[i][j] != a[i][j+1]) {
                    v.push_back(c);
                    c = 0;
                }
            }
            if ((int)v.size() >= 3 && dis==-1) {
                dis = v[1];
            }
            if (dis==-1) continue;

            if (v[0] > dis || v[(int)v.size()-1] > dis) {
                bad = 1;
            }
            for (int t=1; t<(int)v.size()-1; t++) {
                if (v[t] != dis) {
                    bad = 1;
                }
            }
        }
        for (int j=0; j<m; j++) {
            int c = 0;
            vector<int> v;
            for (int i=0; i<n; i++) {
                c++;
                if (i+1==n || a[i][j] != a[i+1][j]) {
                    v.push_back(c);
                    c = 0;
                }
            }
            if ((int)v.size() >= 3 && dis==-1) {
                dis = v[1];
            }
            if (dis==-1) continue;

            if (v[0] > dis || v[(int)v.size()-1] > dis) {
                bad = 1;
            }
            for (int t=1; t<(int)v.size()-1; t++) {
                if (v[t] != dis) {
                    bad = 1;
                }
            }
        }
        if (bad) {
            cout << -1 << nl;
            continue;
        }

        if (dis == -1) {
            cout << 0 << nl;
            continue;
        }

        dbg(dis);

        bool dif = 0;
        int c = 1;
        for (int i=1; i<n; i++) {
            if (!dif) {
                if (a[i-1]!=a[i]) {
                    dif = 1;
                    c = 1;
                } else {
                    c++;
                    if (c > dis) {
                        bad = 1;
                        break;
                    }
                }
            } else {
                if (a[i] != a[i-1]) {
                    if (c < dis) {
                        bad = 1;
                        break;
                    }
                    c = 1;
                } else {
                    c++;
                    if (c > dis) {
                        bad = 1;
                        break;
                    }
                }
            }
        }
        if (bad) {
            cout << -1 << nl;
            continue;
        }
        cout << dis << nl;
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

