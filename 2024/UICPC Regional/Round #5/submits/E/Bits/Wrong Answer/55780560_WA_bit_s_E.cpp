#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int INF = 1e9+7;
const int maxN = 1e5+5;

int arr[maxN];
int q[maxN];

void solve(){
    int n,m, L;
    cin >> n >> m >> L;
    for(int i=0; i<n; i++)
        cin >> arr[i];
    sort(arr , arr+n);
    int l = 0;
    if(arr[0] != 0)
        l = arr[0];
    if(arr[n-1] != L)
        l = max(L-arr[n-1], l);
    for(int i=1; i<n; i++)
        l = max(arr[i]-arr[i-1],l);
    int ans = INF;
    for(int i=0; i<m; i++){
        int a;
        cin >> a;
        if(ans>a && a>= l)
            ans = a;
    }
    if(ans == INF)
        cout << -1 << '\n';
    else
        cout << ans << '\n';
}

int main()
{
    int t=1;
//    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
