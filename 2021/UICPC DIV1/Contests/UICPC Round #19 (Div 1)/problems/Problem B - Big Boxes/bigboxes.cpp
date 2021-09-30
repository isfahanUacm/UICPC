#include <bits/stdc++.h>
using namespace std;

const int maxn = 100003;
int w[maxn], n , k;

bool judge(int lim){
    int tmp = 0, box = 1;
    for (int i = 0; i < n; ++i) {
        if(tmp + w[i] <= lim){
            tmp += w[i];
        }
        else{
            box++;
            tmp = w[i];
        }
    }
    return box <= k;
}

int main()
{
    cin >> n >> k;
    int mx = 0;
    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        mx = max(mx, w[i]);
    }
    int lo = mx, hi = 1e9, mid;
    while(lo < hi){
        mid = (lo + hi) / 2;
        if(judge(mid)){
            hi = mid;
        }
        else{
            lo = mid + 1;
        }
    }
    cout << lo << endl;
    return 0;
}

