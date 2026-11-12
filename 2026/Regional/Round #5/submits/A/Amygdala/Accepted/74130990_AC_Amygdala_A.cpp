#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>
#define all(x) x.begin(),x.end()

const int N = 1e6+9 , INF = 1e18 , mod=998244353 ;
int a[N] , sum[N];

int bs(int x , int n){
    int l=0 , r=n;
    if(a[l] < x){
        return -1;
    }
    while(r-l > 1){
        int mid=(l+r)/2;
        if(a[mid] >= x){
            l=mid;
        }
        else{
            r=mid;
        }
    }
    return l;
}

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    //cin >> T;
    while(T--) {
        int n , m;
        cin >> n >> m;
        for(int i=0 ; i<n ; i++){
            cin >> a[i];
        }
        sort(a , a+n);
        reverse(a , a+n);
        sum[0]=a[0];
        for(int i=1 ; i<n ; i++){
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1 ; i<=m ; i++){
            int x=bs(i , n);

            cout << (x == -1 ? 0  : sum[x]) << ' ';
        }
        cout << endl;
    }

}
