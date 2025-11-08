#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second

const int N = 250000+9;
pii ans[N];
vector<int> adj[N];
void solve()
{

    int n , m , k;
    cin >> n >> m >> k;
    for(int i=0 ; i<510 ; i++){
        for(int j=0 ; j<510 ; j++){
            ans[i*m +j]={0 , 0};
        }

    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            if(i > 0){
                adj[i*m + j].pb((i-1)*m + j);
            }
            if(i < n-1){
                adj[i*m + j].pb((i+1)*m + j);
            }
            if(j > 0){
                adj[i*m + j].pb(i*m + j-1);
            }
            if(j < m-1){
                adj[i*m + j].pb(i*m + j+1);
            }
        }
    }
    queue<int> q;
    for(int i=0 ; i<k ; i++){
        int x , y;
        cin >> x >> y;
        x--;
        y--;
        ans[x*m+y].F=i+1;
        q.push(x*m + y);
    }

    while(!q.empty()){

        int v = q.front();
        q.pop();
        for(int u : adj[v]){
            if(ans[u].F != 0 && ans[u].S != 0)
                continue;
            if(ans[u].F == 0){
                ans[u].F = ans[v].F;
            }
            if(ans[u].S == 0){
                if(ans[v].F != ans[u].F){
                    ans[u].S = ans[v].F;
                }
                else{
                    ans[u].S = ans[v].S;
                }
            }
            q.push(u);

        }

    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout << ans[i*m + j].F << ' ';
        }
        cout << endl;
    }
    for(int i=0 ; i<n ; i++){
        for(int j=0 ; j<m ; j++){
            cout << ans[i*m + j].S << ' ';
        }
        cout << endl;
    }

}

int main()
{
    //ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}