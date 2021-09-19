#include <bits/stdc++.h>
using namespace std;
#define MAX_N 10000010
long long int _sieve_size;
bitset<MAX_N> pFlags;
long long int spf[MAX_N]; // smallest pf of numbers
vector<long long int> PF;

void sieve(long long int upperbound){
    _sieve_size = upperbound + 1;
    pFlags.set();
    pFlags[0] = pFlags[1] = 0;
    for(long long int q = 4; q <= _sieve_size; q += 2){
        pFlags[q] = 0;
        spf[q] = 2;
    }
    PF.push_back(2);
    for(long long int p = 3; p <= _sieve_size; p += 2){ // constraint can be p * p <= _sieve_size if we don't need to calc PF
        if(pFlags[p]){
            spf[p] = p;
            for(long long int q = p * p; q <= _sieve_size; q += p){
                if(pFlags[q]){
                    pFlags[q] = 0;
                    spf[q] = p;
                }
            }
            PF.push_back(p);
        }
    }
}

map<int, int> factors;
void primeFactors(long long int N) { // and also sumPF
    long long int PF_idx = 0, primefactor = PF[PF_idx];
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        if(N % primefactor == 0 && factors.find(primefactor) == factors.end())
            factors[primefactor] = 0;
        while (N % primefactor == 0){
            N /= primefactor; // remove PF
            factors[primefactor]++;
        } 
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        factors[N]++; // special case if N is a prime
}

void primeFactors2(long long int N) { // and also sumPF
    long long int PF_idx = 0, primefactor = PF[PF_idx];
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        while (N % primefactor == 0){
            N /= primefactor; // remove PF
            factors[primefactor]--;
        } 
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        factors[N]--; // special case if N is a prime
}

long long int numDiv() {
    long long int ans = 1; // start from ans = 1
    for(auto aa: factors){
        if(aa.second != 0){
            ans *= (aa.second+1);
        }
    }
    return ans;
}

int main()
{
    sieve(10000);
    int n, k;
    while(cin >> n >> k){
        factors.clear();
        for (int i = max(2, n-k+1); i <= n; ++i) {
            primeFactors(i);
        }
        for (int i = 2; i <= k; ++i) {
            primeFactors2(i);
        }
        cout << numDiv() << endl;
    }
    return 0;
}

