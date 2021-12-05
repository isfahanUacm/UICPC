#include <bits/stdc++.h>
using namespace std;

// Fiat

#define num long long int
const num mod = 1e9 + 7;
const int maxn = 1e5 + 3;

// deciding on bottom-left rectangle's length:
// dp[n] = sum(dp[k-1] * dp[n-k]) for k in [1, n]
// this is n-th catalan number!

bitset<maxn> pf;
vector<num> primes;

num n;
map<num, num> factors;

inline void factorize(num x, int s){
    for(num pf : primes){
        if(pf * pf > x)
            break;
        while(!(x % pf))
            factors[pf] += s, x /= pf;
    }
    if(x > 1)
        factors[x] += s;
}

int main(){
    pf.set();
    for(num p = 2; p < maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
        }
    cin >> n;
    for(num f = n + 2; f <= 2 * n; f++)
        factorize(f, 1);
    for(num f = 2; f <= n; f++)
        factorize(f, -1);
    num ans = 1;
    for(pair<num, num> p : factors){
        num x = p.second;
        while(x--)
            ans = (ans * p.first) % mod;
    }
    cout << ans << endl;
}