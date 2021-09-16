#include <bits/stdc++.h>
using namespace std;

// Fundamental Neighbors

#define num long long int

const int maxn = 1e5 + 1;

bitset<maxn> pf;
vector<num> primes; 
map<num, num> factors;

inline void factorize(num x){
    factors.clear();
    for(num p : primes){
        if(p * p > x)
            break;
        while(!(x % p))
            factors[p]++, x /= p;   
    }
    if(x != 1)
        factors[x]++;
}

num fastpow(num a, num b){
    if(!b)
        return 1;
    if(b % 2)
        return a * fastpow(a, b-1);
    num m = fastpow(a, b/2);
    return m * m;
}

int main(){
    pf.set();
    for(num p = 2; p < maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
        }
    num x;
    while(cin >> x){
        factorize(x);
        num ans = 1;
        for(auto p : factors)
            ans *= fastpow(p.second, p.first);
        cout << x << " " << ans << endl;
    }
}