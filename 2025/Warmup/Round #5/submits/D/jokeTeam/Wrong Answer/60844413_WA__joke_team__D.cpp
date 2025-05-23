#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define TESTCASE
//#define TIME
#ifdef DEBUG
#include "/home/pouya/dev/cp/lib/debug.cpp"
#else
#define dbg(...)
#define TC solve
#endif
#define nl '\n'
void solve(int tc) {
    int n; cin >> n;
    set<string> users;
    map<string, int> cnt;
    while (n--) {
        char c; cin >> c;
        if (c == 'a') {
            string s; cin >> s;
            if (users.count(s)) {
                cnt[s]++;
                cout << s << cnt[s] << nl;
            } else {
                cout << "OK" << nl;
                users.insert(s);
            }
        } else {
            string s; cin >> s;
            if (users.count(s)) {
                users.erase(s);
                cnt[s] = 0;
                cout << "DELETED" << nl;
            } else {
                cout << "INVALID" << nl;
            }
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    for (int i=1; i<=t; i++) {
        TC(i);
    }
    return 0;
}

