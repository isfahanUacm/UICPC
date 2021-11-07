#include <bits/stdc++.h>
using namespace std;

// Factor-Free Tree

bitset<10000001> primeFlags;
int spf[10000001];

inline void init(){
    primeFlags.set();
    for(int p = 2; p <= 10000000; p++)
        if(primeFlags[p]){
            spf[p] = p;
            for(long long int q = ((long long int)p) * p; q <= 10000000; q += p)
                if(primeFlags[q]){
                    primeFlags[q] = 0;
                    spf[q] = p;
                }
        }
}

int n;
int seq[1000001];
int par[1000001];
int before[1000001];
int after[1000001];

bool solve(int start, int end, int parent){
    if(start == end){
        par[start] = parent;
        return true;
    }
    int lptr = start, rptr = end;
    while(lptr < rptr){
        if(before[lptr] < start && after[lptr] > end){
            par[lptr] = parent;
            bool subl = (lptr == start) ? true : solve(start, lptr-1, lptr);
            bool subr = (lptr == end) ? true : solve(lptr+1, end, lptr);
            return subl && subr;
        }
        lptr++;
        if(before[rptr] < start && after[rptr] > end){
            par[rptr] = parent;
            bool subl = (rptr == start) ? true : solve(start, rptr-1, rptr);
            bool subr = (rptr == end) ? true : solve(rptr+1, end, rptr);
            return subl && subr;
        }
        rptr--;
    }
    if(lptr == rptr && before[lptr] < start && after[rptr] > end){
        par[lptr] = parent;
        bool subl = (lptr == start) ? true : solve(start, lptr-1, lptr);
        bool subr = (lptr == end) ? true : solve(lptr+1, end, lptr);
        return subl && subr;
    }
    return false;
}

int pindices[10000001];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> seq[i];
    init();
    fill_n(pindices, 10000001, -1);
    fill_n(before, 1000001, -1);
    for(int i = 0; i < n; i++){
        int k = seq[i];
        while(k != 1){
            int factor = spf[k];
            before[i] = max(before[i], pindices[factor]);
            k /= factor;
        }
        k = seq[i];
        while(k != 1){
            int factor = spf[k];
            pindices[factor] = i;
            k /= factor;
        }
    }
    fill_n(pindices, 10000001, n);
    fill_n(after, 1000001, n);
    for(int i = n-1; i >= 0; i--){
        int k = seq[i];
        while(k != 1){
            int factor = spf[k];
            after[i] = min(after[i], pindices[factor]);
            k /= factor;
        }
        k = seq[i];
        while(k != 1){
            int factor = spf[k];
            pindices[factor] = i;
            k /= factor;
        }
    }
    bool ans = solve(0, n-1, -1);
    if(ans)
        for(int i = 0; i < n; i++)
            cout << par[i]+1 << " ";
    else cout << "impossible";
}