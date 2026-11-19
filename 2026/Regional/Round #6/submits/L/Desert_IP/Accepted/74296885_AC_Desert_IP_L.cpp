#include <iostream>
#include <unordered_map>

#define ll long long

using namespace std;

int main() {
    ll n, k, q, i, j, aa = 0;
    long long x, sum = 0;
    const long long MOD = 1006903069;

    cin >> n >> k;

    unordered_map<long long , long long> mp;

    for (int l = 0; l < k; ++l) {
        cin >> i >> j >> x;
        aa = (j - 1) + ((i - 1) * n);
        mp[aa] = x;
    }

    cin >> q;

    for (int l = 0; l < q; ++l) {
        cin >> i >> j >> x;

        aa = (i - 1) + ((j - 1) * n);

        if (mp.find(aa) != mp.end()) {
            sum = (sum + (mp[aa] * x) % MOD) % MOD;
        }
    }

    cout << sum % MOD;

    return 0;
}