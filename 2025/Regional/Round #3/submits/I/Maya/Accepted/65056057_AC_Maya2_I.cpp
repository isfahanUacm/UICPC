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
    int n; cin >> n;
    dbg(n);
    vector a(n, vector<string>());
    for (int i=0; i<n; i++) {
        int k; cin >> k;
        for (int j=0; j<k; j++) {
            string t; cin >> t;
            transform(t.begin(), t.end(), t.begin(), ::tolower);
            a[i].push_back(t);
        }
    }
    dbg(a);

    string prev = "";
    vector<string> ans;
    for (int i=n-1; i>=0; i--) {
        string mx = "";
        for (int j=0; j<(int)a[i].size(); j++) {
            if (prev=="" || a[i][j] <= prev) {
                mx = max(a[i][j], mx);
            }
        }
        dbg(i, mx);
        if (mx == "") {
            cout << "impossible" << nl;
            return;
        }
        ans.push_back(mx);
        prev = mx;
    }
    reverse(ans.begin(), ans.end());
    for (string t: ans) {
        for (int i=0; i<(int)t.size(); i++) {
            if (i == 0) {
                cout << char('A'+(t[i]-'a'));
            } else {
                cout << t[i];
            }
        }
        cout << nl;
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


