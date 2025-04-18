#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

const int N = 2e5+9 , INF = 2e9;
int a[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    sort(a , a+n);
    int mn=a[0] , cnt=1 , ans=1;
    for(int i=1 ; i<n ; i++){
        if(a[i]-mn <= m && cnt+1 <= k){
            cnt++;
        }
        else{
            mn=a[i];
            cnt=1;
            ans++;
        }
    }
    cout << ans;
}

