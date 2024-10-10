#include<bits/stdc++.h>
#ifndef LOCAL
#define LINE
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);
#else
#define LINE cerr << "----------" << nl;
#define fastio
#endif
using namespace std;
using ll = long long; using ld = long double;
#define nl '\n'
#define arr array
#define pb push_back

vector<vector<ld>> ans;
vector<int> fact;
void prec() {
    fact.resize(11);
    fact[0] = 1;
    for (int i=1; i<=10; i++) {
        fact[i] = i*fact[i-1];
    }


    for (int d=1; d<=9; d++) {
        string s(d, '0');
        iota(s.begin(), s.end(), '1');
        vector<int> nums;
        do {
            nums.pb(stoi(s));
        } while (next_permutation(s.begin(), s.end()));

        int N = nums.size();
        map<int, int> idx;
        for (int i=0; i<N; i++) {
            idx[nums[i]] = i;
        }

        vector<ld> dp(N);
        dp[N-1] = 1;
        ld sum = 1;
        for (int i=N-2; i>=0; i--) {
            dp[i] = 1.0/N*sum;
            sum += dp[i];
        }
        ans.emplace_back(dp);
    }
}

void solve() {
    string s; cin >> s;
    int n = s.size();
    // find x
    vector<bool> vis(n+1);
    vector<int> perm(n);
    for (int i=n-1; i>=0; i--) {
        int num = 0;
        for (int j=0; j<(s[i]-'0'); j++) {
            num += vis[j];
        }
        perm[i] = i == n-1? 0: perm[i+1]+fact[n-i-1]*num;
        vis[(s[i]-'0')] = true;
    }
    int x = perm[0];

    /*
    vector<int> nums;
    string t = s;
    sort(t.begin(), t.end());
    do {
        nums.pb(stoi(t));
    } while (next_permutation(t.begin(), t.end()));

    int N = nums.size();
    map<int, int> idx;
    for (int i=0; i<N; i++) {
        idx[nums[i]] = i;
    }
    int x = idx[stoi(s)];
    */

    if (x == fact[n]-1) {
        cout << fixed << setprecision(9) << 0.0 << nl;
    } else {
        cout << fixed << setprecision(9) << ans[n-1][x] << nl;
    }
}

int32_t main() {
    prec();
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

