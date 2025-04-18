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
int a[N] , dp[N] , p[N];
bool chosen[N] , self[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n , sum=0;
    cin >> n;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
        sum+=a[i];
    }
    if(n==1){
        cout << sum*2 << endl << "M";
        return 0;
    }
    fill(self , self+n , 0);
    dp[n-1]=a[n-1];
    self[n-1]=1;
    self[n-2]=(a[n-1]<a[n-2]);
    dp[n-2]=max(a[n-1] , a[n-2]);
    p[n-1]=n;
    if(a[n-1]<a[n-2])
        p[n-2]=n;
    else
        p[n-2]=n-1;
    for(int i=n-3 ; i>=0 ; i--){
        dp[i]=max(dp[i+2]+a[i] , dp[i+1]);
        if(dp[i+2]+a[i] > dp[i+1]){
            p[i]=i+2;
            self[i]=1;
        }

        else
            p[i]=i+1;
    }
    int cur=0;
    fill(chosen , chosen+n , 0);

    while(cur!=n){
        if(self[cur])
            chosen[cur]=1;
        cur=p[cur];
    }
    int ans=sum+dp[0];
    string pp= to_string(ans);
    cout << fixed<<setprecision(pp.length())<<ans << endl;
    for(int i=0 ; i<n ; i++){
        if(chosen[i])
            cout << 'M';
        else cout << 'O';
    }
}


