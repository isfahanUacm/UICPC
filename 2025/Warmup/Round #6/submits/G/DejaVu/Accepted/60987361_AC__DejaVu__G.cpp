#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

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

    ll x = n / 2;

    ll start = upper_bound(primes.begin(), primes.end(), x) - primes.begin();
    ll end = upper_bound(primes.begin(), primes.end(), n) - primes.begin();

    if (x == 1) {
        cout << end - start - 1 << endl;        
    } else {
        cout << end - start << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int N = 1e7;
    sieve(N); 

    int t = 1;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}