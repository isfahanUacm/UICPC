//In the name of Allah
#include<bits/stdc++.h>

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

const int maxn = 2 * 1e5 + 10;

set<int> adj[maxn] ;
vector<int> az ;
vector<int> azz[maxn] ;
bool mark[maxn] ;





bool test = false ;

void dfs(int v , int n , int ted , int r , bool te){
    if(ted == n){
        test = true ;
        for(int i = 0 ; i<n ; i++)
            cout << az[i] << ' ' ;
        cout << nl ;
        return;
    }
    mark[v] = true ;
    for(int u : adj[v]){
        if(!mark[u]){
            az.pb(u) ;
            dfs(u , n , ted+1 , r , true) ;
            az.pop_back() ;
        }
        else if(r<3){
            dfs(u , n , ted , r+1 , false) ;
        }
        if(test)
            return;
    }
    if(te)
    mark[v] = false ;

}


void solve(){
    int n , m ;
    cin >> n >> m ;
    int u , v ;
    FOR(i , 0 , m){
        cin >> u >> v ;
        adj[u].insert(v) ;
        adj[v].insert(u) ;
    }


    FOR(i , 1 , n+1){
        az.push_back(i) ;
        dfs(i , n , 1 , 0 , true) ;
        az.pop_back() ;
        if(test)
            return;
    }
}



int32_t main(){
    fastio() ;
    int t = 1 ;

    while (t--) {
        solve() ;
    }
    return 0 ;
}
