#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

int cal(int ind,vector<int>& v){
    if(ind == 0)
        return 2 * v[0];

    return 2 * (cal(ind-1,v) + v[ind] - v[ind - 1]);
}




const int N = 2e5+9 , INF = 2e9;
int a[N];

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);

    int n,m;
    cin >> n>>m;
    vector<int>arr(m);

    for (int i = 0; i < m; ++i) {
        cin>>arr[i];
    }

    int res = 0;
    if(m != 0) {
        res = cal(m - 1, arr);

        res = res + (n - arr[m - 1]);
    }
    else res = n;
    cout << res;

}

