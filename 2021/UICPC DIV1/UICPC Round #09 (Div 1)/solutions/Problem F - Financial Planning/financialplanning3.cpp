#include <bits/stdc++.h>
using namespace std;

// Financial Planning

int n;
long long int m, p[100003], c[100003];

bool judge(long long int k){
    long long int sum = 0;
    for(int i = 0; i < n; i++)
        if(p[i] * k - c[i] > 0){
            sum += p[i] * k - c[i];
            if(sum >= m)
                return true;
        }
    return false;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> p[i] >> c[i];
    long long int lo = 1, hi = INT_MAX;
    while(lo < hi){
        long long int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}