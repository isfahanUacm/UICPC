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
map<long long int, long long int> af;
map<long long int, long long int> factors[103];
vector<pair<long long int, long long int>> need;
void primeFactors(long long int N, int idx) { // and also sumPF
    long long int PF_idx = 0, primefactor = PF[PF_idx];
    while (primefactor * primefactor <= N) { // stop at sqrt(N); N can get smaller
        if(N % primefactor == 0){
            long long int power = 0;
            while (N % primefactor == 0){
                N /= primefactor; // remove PF
                power++;
            }
            factors[idx][primefactor]= power;
            af[primefactor] += power;
        }
        primefactor = PF[++PF_idx]; // only consider primes
    }
    if (N != 1)
        factors[idx][N] = 1, af[N]++; // special case if N is a prime
}

int n;
int a[103];
int main()
{
    sieve(100000);
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        primeFactors(a[i], i);
    }
    int factor, power;
    long long int g = 1;
    for(auto vv: af){
        factor = vv.first, power = vv.second;
//        cerr << factor << " " << power << endl;
        if(power/n >= 1){
            g *= pow(factor, power/n);
            need.push_back({factor, power/n});
        }
    }
    int res = 0;
    for (int i = 0; i < n; ++i) {
        for (auto ff: need) {
            if(factors[i][ff.first] < ff.second){
                res += ff.second - factors[i][ff.first];
            }
        }
    }
    cout << g << " " << res << endl;
    return 0;
}

