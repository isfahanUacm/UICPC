#include <bits/stdc++.h>
using namespace std;

// Linear Sieve with Smallest Prime Factor(SPF), O(n)
vector<int> spf, primes;
void sieve(int n) {
    spf.assign(n + 1, 0);

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

    vector<int> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map<int, int> p[n];
    for (int i = 0; i < n; i++) {
        while (spf[s[i]] > 1) {
            p[i][spf[s[i]]]++;
            s[i] /= spf[s[i]];
        }
    }

    map<int, int> ans;
    for (int i = 0; i < n; i++) {
        for (pair<int, int> u : p[i]) {
            ans[u.first] = max(ans[u.first], u.second);
        }
    }

    long res = 0;
    for (pair<int, int> u : ans) {
        res += u.second;
    }

    cout << ((res % 2) ? "Alice" : "Bob") << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1e5;
    sieve(N); 

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}