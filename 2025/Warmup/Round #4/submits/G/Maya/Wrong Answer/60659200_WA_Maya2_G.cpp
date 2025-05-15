#include <bits/stdc++.h>
using namespace std;

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

const int N = 2e6;

vector<int> spf, primes;
void sieve(int n) {
    spf.assign(n + 1, 0);

    spf[1] = 1;
    for (int i = 2; i <= n; i++) {
        if (spf[i] == 0) {
            spf[i] = i;
            primes.push_back(i);
        }
        for (int j = 0; j < (int)primes.size() && i * primes[j] <= n && primes[j] <= spf[i]; j++) {
            spf[i * primes[j]] = primes[j];
        }
    }
}

void solve() {
    int n;
    cin >> n;

    vector<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i][0];
        a[i][1] = i;
    }
    sort(a.begin(), a.end());

    vector<int> dp(N + 1), mx(N + 1), mx_ind(N + 1, -1), path(N + 1, -1);
    dp[1] = 1;
    for (int i = 0; i < n; i++) {
        if (i == 0 || a[i][0] != a[i - 1][0]) {
            int x = a[i][0], mxx = 0, par = 0;
            while (spf[x] != x) {
                if (mx[spf[x]] > mxx) {
                    mxx = mx[spf[x]];
                    par = mx_ind[spf[x]];
                    path[a[i][1]] = par;
                }
                x = x / spf[x];
            }
            if (mx[spf[x]] > mxx) {
                mxx = mx[spf[x]];
                par = mx_ind[spf[x]];
                path[a[i][1]] = par;
            }
            dp[a[i][0]] = mxx + 1;

            x = a[i][0];
            while (spf[x] != x) {
                if (dp[a[i][0]] > mx[spf[x]]) {
                    mx[spf[x]] = dp[a[i][0]];
                    mx_ind[spf[x]] = a[i][1];
                }
                x = x / spf[x];
            }
            if (dp[a[i][0]] > mx[spf[x]]) {
                mx[spf[x]] = dp[a[i][0]];
                mx_ind[spf[x]] = a[i][1];
            }
        }
    }

    auto ind = max_element(dp.begin(), dp.end()) - dp.begin();
    cout << dp[ind] << '\n';
    for (int i = 0; i < n; i++) {
        if (a[i][0] == ind) {
            ind = a[i][1];
            break;
        }
    }

    vector<int> ans;
    while (ind != -1) {
        ans.push_back(ind);
        ind = path[ind];
    }
    reverse(ans.begin(), ans.end());

    for (auto x : ans) {
        cout << x + 1 << ' ';
    }
    cout << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    sieve(N);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
