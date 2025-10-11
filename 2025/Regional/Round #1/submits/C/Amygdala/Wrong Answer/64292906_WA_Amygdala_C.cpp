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

    ll ans = 0;
//    int p = 0;
//    for(int u = s-1; u>=0; u--){
//        for(int v=-p; v<=p; v++){
//            ans = (ans + g[x+u][y+v])%mod;
//            ans = (ans + g[x-u][y+v])%mod;
//        }
//    }

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++){
            if(abs(x-i)+abs(y-j) < s)
                ans = (ans + g[i][j]) % mod;
        }
    cout << "Case " << t << ": " << ans << '\n';

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("treasures.in", "r", stdin);

    int t = 1;
    cin >> t;
    for(int i=0; i<t; i++)
    {
        solve( i+1);
    }

//    cout << generate('d', 5, 31, 12);

    return 0;
}