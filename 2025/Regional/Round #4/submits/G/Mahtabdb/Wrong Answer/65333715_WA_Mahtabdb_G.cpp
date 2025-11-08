#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

long long modpow(long long a, long long b, long long mod) {
    long long res = 1;
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

    int p = 2*k + 1;
    
    long long num = n * modpow(p-1, n-1, MOD) % MOD;
    long long den = modpow(p, n-1, MOD);
    long long den_inv = modpow(den, MOD-2, MOD);

    long long answer = num * den_inv % MOD;
    cout << answer << endl;

    return 0;
}