#include <bits/stdc++.h>
using namespace std;

// Divisors

#define num long long int

const int maxn = 433;

int spf[maxn], n, k;

map<int, num> factors;

int main(){
    iota(spf, spf + maxn, 0);
    for(int p = 2; p < maxn; p++)
        if(spf[p] == p)
            for(int q = p * p; q < maxn; q += p)
                if(spf[q] == q)
                    spf[q] = p;
    while(cin >> n >> k){
        factors.clear();
        for(int i = k + 1; i <= n; i++){
            int x = i;
            while(x > 1)
                factors[spf[x]]++, x /= spf[x];
        }
        for(int i = 1; i <= n - k; i++){
            int x = i;
            while(x > 1)
                factors[spf[x]]--, x /= spf[x];
        }
        num ans = 1;
        for(auto p : factors)
            ans *= (p.second + 1);
        cout << ans << endl;
    }
}