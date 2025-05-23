#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define  endl '\n'
void solve() {
    int n;
    cin>>n;
    vector<ll> arr(n);
    for (int i = 0; i < n; ++i) {
        cin>>arr[i];
    }

    vector<ll> sum(n+1);
    sum[0] = 0;
    for(int i = 1 ; i <= n;i++){
        sum[i] = sum[i-1] + arr[i-1];
    }

    ll best  = 0;
    for(int k =0;k < n/2;k++){
        if(n % (k+1)) continue;

        ll min = LLONG_MAX;
        ll max = -1;
        for(int i = 1 ; i+k <= n ; i+= k+1){
            int j = i + k;

            if(sum[j]-sum[i-1] < min)
                min = sum[j]-sum[i-1];
            if (sum[j]-sum[i-1] > max)
                max = sum[j]-sum[i-1];
        }

        if((max - min) >  best )
            best = max - min;
    }

    cout << best;

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin>>t;
    while (t--)
    {
        solve();
        if (t != 0)
            cout << '\n';
    }
}
