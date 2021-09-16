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
                pFlags[q] = 0;
                spf[q] = p;
            }
            PF.push_back(p);
        }
    }
}

bool isPrime(long long int N) {
    if (N <= _sieve_size)
        return pFlags[N];
    for (int i = 0; i < (int)PF.size(); i++){
        if (N % PF[i] == 0)
            return false;
    }
    return true; // it takes longer time if N is a large prime!
} // note: only work for N <= (last prime in PF)^2

int n;

int main()
{
    sieve(100000);
    while(cin >> n && n){
        for (long long int i = 2*n + 1; i < LLONG_MAX; ++i) {
            if(isPrime(i)){
                cout << i;
                break;
            }
        }
        if(!isPrime(n)){
            cout << " (" << n <<" is not prime)";
        }
        cout << endl;
    }
    return 0;
}

