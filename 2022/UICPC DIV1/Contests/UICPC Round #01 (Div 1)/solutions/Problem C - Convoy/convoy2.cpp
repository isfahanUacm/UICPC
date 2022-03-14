#include <bits/stdc++.h>
using namespace std;

// Convoy

#define num long long int

num n, k;
num t[20003];

bool judge(num d){
    num all = n;
    for(int i = 0; i < min(n, k); i++){
        if(t[i] > d)
            return false;
        num z = (d / t[i] + 1) / 2;
        all -= 4 * z + 1;
        if(all <= 0)
            return true;
    }
    return false;
}

int main(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> t[i];
    sort(t, t + n);
    num lo = 0, hi = 1e12;
    while(lo < hi){
        num mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else lo = mid + 1;
    }
    cout << lo << endl;
}