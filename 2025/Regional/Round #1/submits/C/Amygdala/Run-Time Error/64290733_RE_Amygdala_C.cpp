#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
const int mod = 1e9+7;

bool mark[105][105];
int g[105][105];

void solve(int t)
{
    memset(mark,0,sizeof mark);
    int n,m,s,x,y;  cin >> n >> m >> s >> x >> y;
    x--; y--;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> g[i][j];

    queue<pair<int,int>> q;
    q.push({x,y});
    mark[x][y] = 1;
    ll ans = g[x][y];
    while(s--){
        int sz = q.size();
        while(sz--){
            int u = q.front().first, v = q.front().second;
            q.pop();
            if(u+1 < n && !mark[u+1][v]){
                ans = (ans+g[u+1][v])% mod;
                mark[u+1][v] = 1;
                q.push({u+1,v});
            }
            if(u-1 >= 0 && !mark[u-1][v]){
                ans = (ans+g[u-1][v])% mod;
                mark[u-1][v] = 1;
                q.push({u-1,v});
            }
            if(v+1 < m && !mark[u][v+1]){
                ans = (ans+g[u][v+1])% mod;
                mark[u][v+1] = 1;
                q.push({u,v+1});
            }
            if(v-1 >=0 && !mark[u][v-1]){
                ans = (ans+g[u][v-1])% mod;
                mark[u][v-1] = 1;
                q.push({u,v-1});
            }
        }
    }
    cout << "Case " << t << ": " << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << generate('d', 5, 31, 12);

    return 0;
}