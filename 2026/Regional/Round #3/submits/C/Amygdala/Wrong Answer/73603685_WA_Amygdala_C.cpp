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
    int n;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    int ans=0 , l=0 , r=n-1;
    while(l < r){
        if(a[r]-a[l] < r-l+1){
            break;
        }
        if(a[l+1] - a[l] < a[r]-a[r-1]){
            r--;
        }
        else{
            l++;
        }
        ans++;
    }
    cout << ans << '\n';


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