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
    array<string, 3> a{};
    for (int i=0; i<3; i++) {
        cin >> a[i];
    }
    array<int, 3> idx{};
    array<bool, 3> done{};
    dbg(a);
    vector<int> ans;
    while (!(done[0] && done[1] && done[2])) {
        int x = 0;
        for (int i=0; i<3; i++) {
            x ^= a[i][idx[i]]-'0';
        }
        bool put = 0;
        for (int i=0; i<3; i++) {
            if (a[i][idx[i]]-'0' != x) {
                if (!put) {
                    ans.push_back(a[i][idx[i]]-'0');
                    put = 1;
                }
                idx[i]++;
                if (idx[i] == (int)a[i].size()) {
                    done[i] = 1;
                }
            }
        }
    }
    for (int t: ans) {
        cout << t;
    }
    cout << nl;
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


