#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 200005
#define mxa 1000006
const long long inf=LLONG_MAX/5;


vector<int> adj[mxn];
struct fenwick{
    int fen[mxn];
    void upd(int i, int x){
        while (i<mxn){
            fen[i]+=x;
            i+=i&(-i);
        }
    }
    int get(int i){
        int res=0;
        while (i){
            res+=fen[i];
            i-=i&(-i);
        }
        return res;
    }
} fen;
map<int, bool> mrk;
int timer=1;
int st[mxn], en[mxn], a[mxn];
void DFS(int u, int p){
    st[u]=timer++;
    bool flg=0;
    if (mrk[a[u]]==0){
        flg=1;
        mrk[a[u]]=1;
    } 
    for (auto v:adj[u]) if(v!=p){
        DFS(v,u);
    }
    en[u]=timer++;
    if (flg){
        mrk[a[u]]=0;
        fen.upd(st[u], 1);
        fen.upd(en[u]+1, -1);
    }
}
signed main(){
    FastIO
    int n, q;
    cin>>n>>q;
    FOR(i,1,n) cin>>a[i];
    FOR(i,1,n-1){
        int u, v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    DFS(1,-1);
    while (q--){
        int u;
        cin>>u;
        cout<<fen.get(st[u])<<"\n";
    }
}