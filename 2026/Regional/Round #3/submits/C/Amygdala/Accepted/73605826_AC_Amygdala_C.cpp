#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define int ll
#define endl '\n'

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
    int cnt=1 , ans=0;
    for(int i=1 ; i<n ; i++){
        if(a[i]-a[i-1] <= 1){
            cnt++;
        }
        else{
            ans=max(ans , cnt);
            cnt=1;

        }
    }
    ans=max(ans , cnt);
    cout << n-ans << endl;

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