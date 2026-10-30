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

const int N = 1e6+9 , INF = 1e18 ;

int32_t main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T=1;
    cin >> T;
    while(T--) {
        int n;  cin >> n;
        vector<pair<int,int>> l(n), c(n);
        for(int i=0; i<n; i++) {
            int j;  cin >> j;
            l[i] = {j,i};
        }
        for(int i=0; i<n; i++){
            int j;  cin >> j;
            c[i] = {j,i};
        }
        sort(l.begin(), l.end());
        sort(c.rbegin(), c.rend());

        vector<vector<int>> ans(n,vector<int>(n));
        for(int i=0; i<n; i++){
            for(int j=0;j<n; j++)
                ans[i][j] = 0;
        }
        int j=0;
        for(int i=0 ; i<n ; i++){
            int temp=c[i].F;
            for(; j<n ; j++){
                if(l[j].F < temp){
                    temp-=l[j].F;
                    ans[l[j].S][c[i].S]=l[j].F;
                }
                else{
                    l[j].F-=temp;
                    ans[l[j].S][c[i].S]=temp;
                    break;
                }
            }
        }



        for(int k=0; k<n; k++){
            for(j=0;j<n; j++)
                cout << ans[k][j] << " ";
            cout << '\n';
        }
        for(int k=0; k<n; k++){
            cout << l[k].second+1 << " ";
        }
        cout << '\n';
    }




    return 0;

}
