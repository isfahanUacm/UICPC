#include<bits/stdc++.h>
#include <numeric>
using namespace std;
using ll = long long;
using ld = long double;
//#define TESTCASE
//#define TIME
#define DEBUG
#ifdef LOCAL
#include "local.h"
#else
#define dbg(...)
#define Solve solve
#endif
#define nl '\n'

void solve([[ maybe_unused ]] int tc) {
    int n; cin >> n;
    string s, t; cin >> s >> t;
    string ans;
    for (int i=0; i<n; i++) {
        int res = 1e9;
        char c = 'a';
        array<int, 4> a{s[i]-'a', s[n-i-1]-'a', t[i]-'a', t[n-i-1]-'a'};
        for (int j=0; j<26; j++) {
            int sum = 0;
            for (int k=0; k<4; k++) {
                sum += abs(a[k] - j);
            }
            if (sum <= res) {
                c = char('a'+j);
                res = sum;
            }
        }
        ans += c;
    }
    cout << ans << nl;
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

