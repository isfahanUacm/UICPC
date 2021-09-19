#include <bits/stdc++.h>
using namespace std;

// Iks

const int maxn = 1e6 + 1;

#define num long long int

bitset<maxn> pf;
vector<num> primes;
map<num, num> factors;

inline void factorzie(num x){
    for(num p : primes){
        if(p * p > x)
            break;
        while(!(x % p))
            factors[p]++, x /= p;
    }
    if(x != 1)
        factors[x]++;
}

int n;
num a[103], ans = 1, ways = 0;
map<num, num> ansf;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    pf.set();
    for(num p = 2; p < maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0; 
        }
    for(int i = 0; i < n; i++)
        factorzie(a[i]);
    for(auto p : factors)
        if(p.second / n)
            ansf[p.first] = p.second / n;
    for(auto p : ansf){
        num rep = p.second;
        while(rep--)
            ans *= p.first;
    }
    if(ans == 1){
        cout << "1 0" << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        factors.clear();
        factorzie(a[i]);
        for(auto p : ansf)
            ways += max(0ll, p.second - factors[p.first]);
    }
    cout << ans << " " << ways << endl;
}