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
int a[N] , b[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n , k;
    cin >> n >> k;
    for(int i=0 ; i<n ; i++){
        cin >> a[i];
    }
    for(int i=1 ; i<n ; i++){
      b[i]=abs(a[i]-a[i-1]);
    }
    sort(b , b+n-1);
    int res;

    if(n-k == 0) {
        if(b[0] <= 1)
            res = -1;
        else res = 1;
    }
    else {
        if(b[n-k-1]!=b[n-k])
            res = b[n-k] - 1;
        else res =-1;
    }

    cout << (res ==0 ? -1 : res);

}


