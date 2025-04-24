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
    string a; cin >> a;
    stack<ll> stk;
    dbg(a);
    // (*)
    // (****)
    int lev = 0;
    for (int i=0; i<n; i++) {
        char c = (a[0]=='('?-1:-2);
        if (a[i] == ')') {
            ll res = 1;
            int cnt = 0;
            while (stk.size() && stk.top() != -1) {
                res *= stk.top();
                cnt++;
                stk.pop();
            }
            stk.pop();
            if (cnt == 0) {
                stk.push(1);
            } else {
                stk.push(res+1);
            }
            
        } else {
            stk.push(c);
        }
        //dbg(stk);
    }
    ll res = 1;
    while (stk.size()) {
        res *= stk.top();
        stk.pop();
    }
    cout << res << nl;
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

