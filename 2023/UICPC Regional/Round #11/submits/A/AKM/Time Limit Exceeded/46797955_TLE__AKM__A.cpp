//In the name of Allah
#include<vector>
#include<sstream>
#include<iostream>
using namespace std ;

#define fastio() ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
#define MOD 1000000007
#define MOD1 998244353
#define LL_INF 1e18 + 100
#define INT_INF 1e9 + 100
#define MAXN int(1e5 + 100)
#define ll long long int
#define ld long double
#define pii pair<int,int>
#define pil pair<ll,ll>
#define pid pair<double,double>
#define vi vector<int>
#define vl vector<ll>
#define vd vector<double>
#define F first
#define S second
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define pf push_front
#define nl '\n'
#define FOR(i ,a ,b) for(int i = (a) ; i<(b) ; i++)
#define sz(x) ((int)(x).size())
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin(), x.rend()

const int maxn = 2*1e5 + 100 ;

vector<ll> adj[maxn] ;

bool mark[maxn] ;

ll ans = 0 ;


void dfs(ll u , ll m){
    ans = max(ans , m) ;

    mark[u] = true ;
    ll cnt = 0 ;
    ll last =1;
    for(ll v : adj[u]){
        if(cnt % 2 == 1 && !mark[last]) dfs(last , m+v) ;
        last = v ;
        cnt++ ;
    }

    mark[u] = false ;
}

void solve(){
    ll n ,  k ;
    cin >> n >> k ;
    ll u , v , m;
    ll maxi = 0 ;
    FOR(i , 0 , n-1){
        cin >> u >> v >> m ;
        adj[u].pb(v) ;
        adj[u].pb(m) ;
        adj[v].pb(u) ;
        adj[v].pb(m) ;
        maxi += m ;
    }

    if(k > 1){
        cout << maxi << nl ;
    }
    else
    {
        FOR(i , 1 , n+1){
            if(adj[i].size() == 2)
                dfs(i , 0) ;
        }
        cout << ans << nl ;
    }
    return;
}




int32_t main(){
    fastio() ;
    int t = 1 ;
    while (t--) {
        solve() ;
    }
    return 0 ;
}
