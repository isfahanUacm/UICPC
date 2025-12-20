#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N=2e5+9, INF=1e9+7;
int a[N];

int32_t main(){
    while(true) {
        int n, m;
        cin>>n>>m;
        int ans = m;
        if (n == 0 && m == 0) {
            return 0;
        }
        for(int i=0;i<n;i++) cin>>a[i];
        sort(a,a+n);
        for (int i = 1 ; i < n ; i++) {
            if (a[i] == a[i-1]) {
                for (int j = i + 1; j < n ; j++) {
                    swap(a[j], a[j-1]);
                }
                n--;
                i--;
            }
        }
        //for(int i=0;i<n;i++) cout<<a[i]<<" ";
        cout<<endl;
        int les = m / 7;
        les *= 2;
        if (m % 7 == 6) les++;
        ans = les;
        //cout<<ans<<endl;
        for (int i = 0 ; i < n ; i++) {
            if (a[i] <= m) {
                if (a[i] % 7 != 6 && a[i] % 7 != 0) {
                    ans++;
                }
            }
        }
        //cout << ans << " " << les << " " << cnt << endl;
        int zero = 0;
        cout << max(zero, m - ans) << endl;
    }
    return 0;
}