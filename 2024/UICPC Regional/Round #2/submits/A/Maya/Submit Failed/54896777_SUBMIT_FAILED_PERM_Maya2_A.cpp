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

void solve() {
    int n; cin >> n;
    int cnt = 0;
    vector<int> v;
    int t = n;
    while (t) {
        cnt++;
        v.pb(t%10);
        t /= 10;
    }
    sort(v.begin(), v.end());

    vector<int> nums;
    do {
        int x = 0;
        for (int i=0; i<cnt; i++) {
            x = (10*x)+v[i];
        }
        nums.pb(x);
    } while (next_permutation(v.begin(), v.end()));
    sort(nums.begin(), nums.end());
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
    if (idx[n] == N-1) {
        cout << fixed << setprecision(9) << 0.0 << nl;
    } else {
        cout << fixed << setprecision(9) << dp[idx[n]] << nl;
    }
}

int32_t main() {
    fastio
    int t = 1;
cin >> t;
    while (t--) {
        solve();
        LINE
    }
    return 0;
}

