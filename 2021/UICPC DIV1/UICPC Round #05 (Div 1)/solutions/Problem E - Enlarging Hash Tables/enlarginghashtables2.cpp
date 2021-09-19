#include <bits/stdc++.h>
using namespace std;

// Enlarging Hash Tables

#define num long long int

const int maxn = 46341;
bitset<maxn> pf;
vector<int> primes;

inline bool prime(int n){
    int sq = sqrt(n);
    for(int i : primes){
        if(i > sq)
            break;
        if(!(n % i))
            return false;
    }
    return true;
}

int main(){
    pf.set();
    for(num p = 2; p < maxn; p++)
        if(pf[p]){
            primes.push_back(p);
            for(num q = p * p; q < maxn; q += p)
                pf[q] = 0;
        }
    int n;
    while(1){
        cin >> n;
        if(!n)
            break;
        int ans = 2 * n + 1;
        while(!prime(ans))
            ans++;
        cout << ans;
        if(!prime(n))
            cout << " (" << n << " is not prime)";
        cout << endl;
    }
}