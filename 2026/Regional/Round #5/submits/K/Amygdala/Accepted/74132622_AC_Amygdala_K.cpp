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

const int N = 1e5+9 , INF = 1e18 , mod=998244353 ;
int cnt[N] , ind[N];
vi vec[N] , sum;
set <int> s;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    //cin >> T;
    while(T--) {
        int n,q;    cin >> n >> q;
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        while(q--){
            int cmd, l, r;  cin >> cmd >> l >> r;
            if(cmd == 1){
                int x;  cin >> x;
                for(int i=l-1; i<r; i++){
                    v[i] = v[i]%x;
                }
            }
            else if(cmd ==2){
                int x;  cin >> x;
                for(int i=l-1; i<r; i++){
                    v[i] = max(v[i],x);
                }
            }
            else{
                int sum = 0;
                for(int i=l-1; i<r; i++){
                    sum += v[i];
                }
                cout <<sum << '\n';
            }
        }
    }

}