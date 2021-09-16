#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[103], b[103], c[103], d[103];
long long int cnt;

bool judge(int t1, int t2){
    cnt = 0;
    for (int i = 0; i < n; ++i) {
        if(t1 >= a[i]){
            cnt += 1 + (t1-a[i]) / b[i];
        }
    }
    for (int i = 0; i < m; ++i) {
        if(t2 >= c[i]){
            cnt -= 1 + (t2-c[i]) / d[i];
        }
    }
//    cerr << cnt << endl;
    return cnt >= 0;
}

int main()
{
    cin >> t;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }
    cin >> m;
    for (int i = 0; i < m; ++i) {
        cin >> c[i] >> d[i];
    }
    int lo = 0, hi = t, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
//        cerr << mid << endl;
        if(judge(mid, t-mid)){
            hi = mid;
        }
        else{
            lo = mid+1;
        }
    }
    judge(lo, t-lo);
    if(cnt > 0){
        cout << lo-1 << endl;
    }
    else{
        cout << lo << endl;
    }
    return 0;
}

