#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

const int N = 105;
vi vis(N);
vi cycle;
vi edge[N];
vi ans(N , 1e9);

void dfs(int x , int par){
    vis[x] = 1;
    cycle.push_back(x);
    for(int u : edge[x]){
        if(!vis[u]){
            dfs(u , x);
        }
        else{
            if(u != par && par != 0){
                int size = (int)cycle.size();
                int cnt = -1;
                for (int i = 0; i < size; ++i) {
                    if(cycle[i] == u){
                        cnt = size - i;
                    }
                    if(cnt != -1){
                        ans[cycle[i]] = min(cnt , ans[cycle[i]]);
                    }
                }
            }
        }
    }
    vis[x] = 0;
    cycle.pop_back();
};

void solve() {
    int n , m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int u , v;
        cin >> u >> v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dfs(1 , 0);
    ll out = 0;
    for (int i = 1; i <= n ; ++i) {

        if(ans[i] == 1e9){
            out += i;
        }
        else{
            out += (ll)(i * ans[i]);
        }
    }
    cout << out;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}