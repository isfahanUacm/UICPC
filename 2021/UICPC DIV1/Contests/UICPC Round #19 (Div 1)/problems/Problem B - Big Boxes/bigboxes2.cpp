#include <bits/stdc++.h>
using namespace std;

// Big Boxes

const int maxn = 1e5 + 3;

int n, k, a[maxn];

bool judge(int cap){
    int box = 1, curr = a[0];
    for(int i = 1; i < n; i++){
        if(curr + a[i] <= cap)
            curr += a[i];
        else
            box++, curr = a[i];
    }
    return box <= k;
}

int main(){
    int lo = 0, hi = 1000000000;
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> a[i], lo = max(lo, a[i]);
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
}