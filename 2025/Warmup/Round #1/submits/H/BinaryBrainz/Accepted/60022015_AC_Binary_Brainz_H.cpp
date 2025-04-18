#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define F first
#define S second
#define pb push_back
#define pii pair<int,int>
#define vi vector <int>

const int N = 2e5+9 , INF = 2e9;
int par[N];

vi ch[N];

int dfs(int v){
    int ans=0;
    for(int u : ch[v]){
        ans+=dfs(u)+1;
    }
    return ans;
}

int32_t main(){
    ios::sync_with_stdio(0);cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i=1 ; i<=n ; i++){
        cin >> par[i];
        if(par[i]!=0){
            ch[par[i]].pb(i);
        }
    }
    int mx=0 , index=1;
    for(int i=1 ; i<=n ; i++){
        if(par[i]==0){
            int cnt = dfs(i);
            if(cnt > mx) {
                mx = max(mx, dfs(i));
                index=i;
            }
        }
    }
    cout << index << " " << mx+1;

}


