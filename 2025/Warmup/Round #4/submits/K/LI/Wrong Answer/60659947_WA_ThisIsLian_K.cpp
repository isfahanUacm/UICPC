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

int cnt[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n , d;
    cin >> n >> d;
    fill(cnt , cnt+n+10 , 0);
    for(int i=0 ; i<d ; i++){
        int a , b;
        cin >> a >> b;
        cnt[a]++;
        cnt[b]++;
    }
    int mx=0 , sum=0;
    for(int i = 1 ; i<=n ; i++){
        mx = max(mx , cnt[i]);
    }
    for(int i=1 ; i<=n ; i++){
        cnt[i]=mx-cnt[i];
        sum+=cnt[i];
    }

    if(sum%2==1) {
        for (int i = 1; i <= n; i++) {
            cnt[i]++;
            sum++;
        }
        mx++;
    }

    int add=0;
    for(int i=1 ; i<=n ; i++){
        if(cnt[i] > sum-cnt[i])
            add = ((sum-cnt[i]-cnt[i])/(n-2)) + ((sum-cnt[i]-cnt[i])%(n-2)!=0);
    }
    for(int i=1 ; i<=n ; i++){
        cnt[i]+=add;
        sum+=add;
    }
    if(sum%2==1) {
        for (int i = 1; i <= n; i++) {
            cnt[i]++;
            sum++;
        }
        mx++;
    }
    cout << mx;

}


