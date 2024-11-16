#include <bits/stdc++.h>
using namespace std;

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

#ifdef DEBUG
#include "/home/mohammad/code/debug.h"
#else
#define dbg(...)
#endif

void solve() {
    int n;
    cin >> n;

    const int N = 1e7;
    sieve(N);
    for (int i = 0; i < n; i++) {
        long double a, b;
        cin >> a >> b;
        int aa = a * 1000000, bb = b * 1000000;
        int g = gcd(aa, bb);
        aa /= g; bb /= g;
        if (spf[aa] == aa && spf[bb] == bb) {
            cout << aa << ' ' << bb << '\n';
        }
        else {
            cout << "impossible\n";
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    //cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}
