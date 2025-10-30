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
    string a; cin >> a;
    vector<int> cnt(30);
    for (char c: a) {
        cnt[c-'a']++;
    }
    int c =  0;
    for (int i=0; i<26; i++) {
        if (cnt[i] & 1) {
            c++;
        }
    }
    cout << (c <= 1? "yes" : "no") << nl;
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

