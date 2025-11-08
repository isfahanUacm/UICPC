#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
    a %= mod;
    while(b > 0) {
        if(b & 1) res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

int main() {
    int n, k;
    cin >> n >> k;

    int total_ways = n - 1;
    long long numerator = modpow(2LL * k, total_ways, MOD) * (2LL * k + 1) % MOD;
    long long denominator = modpow(2LL * k + 1, total_ways, MOD);

    long long denominator_inv = modpow(denominator, MOD - 2, MOD);
    long long answer = numerator * denominator_inv % MOD;

    cout << answer << "\n";
    return 0;
}