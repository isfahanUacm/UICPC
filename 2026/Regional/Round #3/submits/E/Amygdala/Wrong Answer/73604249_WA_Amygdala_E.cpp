#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define int ll

int const N =  1e6+9;
int const INF = 1e9;
ll const mod = 1e9;

int a[N];

void solve() {
//    int n;
//    cin >> n;
//    for(int i=0 ; i<n ; i++){
//        cin >> a[i];
//    }
//    sort(a , a+n);
//    int ans=0 , cnt=1;
//    for(int i=1 ; i<n ; i++){
//        if(a[i]-a[i-1] <= 1){
//
//        }
//    }
    ll n,k;  cin >> n >> k;
    vector<int> v(n);
    vector<ll> sum(n);
    cin >> v[0];
    sum[0] = v[0];
    for(int i=1; i<n; i++){
        cin >> v[ i];
        sum[i] = sum[i-1]+v[i];
    }
    vector<int> cnt(n);
    int last = v[0];
    cnt[0] = 1;
    cout << k+sum[0];
    for(int i=1; i<n; i++){
        cnt[i] = cnt[i-1];
        if(v[i] > last){
            last = v[i];
            cnt[i]++;
        }

        if(cnt[i] > last){
            cout << " " << sum[i]+ ((k+1)*(k))/2 - ((cnt[i]-1)*cnt[1])/2;
        }
        else{
            cout << " " << sum[i]+k*cnt[i];
        }
    }
    cout << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}