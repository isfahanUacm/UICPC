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

const int N = 1e6+9 , INF = 1e18 , mod=1006903069;


int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    //cin >> T;
    while(T--) {
        int n , b;
        cin >> n >> b;
        int mx=-INF , sum=0;
        for(int i=0 ; i<n-1 ; i++){
            int a;
            cin >> a;
            sum+=max(0ll , a);
            mx=max(a , mx);
        }
        cout << (sum> 0 ? sum+b : max(-1ll , mx+b)) << endl;
    }

}