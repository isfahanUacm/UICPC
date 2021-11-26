#include <bits/stdc++.h>
using namespace std;

// Dropping Directions

const int maxn = 1e5 + 3;

int n, g, from[maxn][2 + 3], to[maxn][2 + 3];
bool vis[maxn][2 + 3];

bool ok;
void dfs(int u, int f){
    vis[u][f] = true;
    if(u == g)
        ok = true;
    int v = to[u][f];
    int f2 = 0;
    for(; f2 < 4; f2++)
        if(from[v][f2] == u)
            break;
    if(!vis[v][f2])
        dfs(v, f2);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> g, g--;
        int a, b, c, d;
        for(int i = 0; i < n; i++){
            cin >> a >> b >> c >> d, a--, b--, c--, d--;
            from[i][0] = a, to[i][0] = c;
            from[i][1] = c, to[i][1] = a;
            from[i][2] = b, to[i][2] = d;
            from[i][3] = d, to[i][3] = b; 
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++)
                vis[i][j] = false;
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < 4; j++)
                if(!vis[i][j]){
                    ok = false;
                    dfs(i, j);
                    if(!ok)
                        ans++;
                }
        cout << ans / 2 << endl;
    }
}