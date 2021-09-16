#include <bits/stdc++.h>
using namespace std;

// Svada

#define num long long int

int t, n, m, a[103], b[103], c[103], d[103];

num coco1(int t){
    num ans = 0;
    for(int i = 0; i < n; i++)
        if(t >= a[i])
            ans += 1 + (t - a[i]) / b[i];
    return ans;
}

num coco2(int t){
    num ans = 0;
    for(int i = 0; i < m; i++)
        if(t >= c[i])
            ans += 1 + (t - c[i]) / d[i];
    return ans;
}


int main(){
    cin >> t >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i] >> b[i];
    cin >> m;
    for(int i = 0; i < m; i++)
        cin >> c[i] >> d[i];
    int lo = 0, hi = t;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        num c1 = coco1(mid), c2 = coco2(t - mid);
        if(c1 > c2)
            hi = mid - 1;
        else
            lo = mid;
    }
    cout << lo << endl;
}