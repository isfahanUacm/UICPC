#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

bool mark[100005];
int adj[100005];
int l[100005];
int cnt, last;
void dfs(int v){
    if(!mark[v]) {
        cnt++;
        mark[v] = 1;
        if (adj[v] == 0)
            last = v;
        else
            dfs(adj[v]);
        l[v] = last;
    }
    else
        last = l[v];
}
void solve()
{
    cint(n);
    for(int i=1; i<=n; i++) cin >> adj[i];
    map<int,int> mp;
    for(int i=1; i<=n; i++){
        if(!mark[i]){
            cnt = 0;
            dfs(i);
            mp[last] += cnt;
        }
    }
    pair maxm = {0,0};
    for(auto p : mp){
        if(maxm.second < p.second)
            maxm = p;
    }
    cout << maxm.first << " " << maxm.second << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}