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
#define sz(x) ((int)(x).size())
#define all(x) x.begin() , x.end()
#define rall(x) x.rbegin(), x.rend()




void solve(){
    pii s[4] = {{1 , 0 } , {-1 , 0} , {0 , 1} , {0 , -1}  } ;
    int n , m , Si , Sj;
    cin >> m >> n ;
    char arr[n][m] ;
    vector<vector<bool>> fire(n , vector<bool> (m , false)) ;
    for(int i = 0 ; i<n;  i++)
        for(int j = 0 ; j<m ; j++){
            cin >> arr[i][j] ;
            if(arr[i][j]=='P'){
                Si = i ;
                Sj = j ;
            }

        }
    for(int i = 0 ; i<n;  i++)
        for(int j=0 ; j<m ; j++)for(int k=0 ; k<4 ; k++)
            for(int k=0 ; k<4 ; k++)
            if(i+s[k].F<n && i+s[k].F>=0 && j+ s[k].S <m && j + s[k].S >=0){
                if(arr[i+s[k].F][j+ s[k].S]=='T')
                    fire[i][j] = true ;
            }
    ll ans = 0 ;
    vector<vector<bool>> visited(n , vector<bool> (m , false)) ;
    vector<vector<bool>> score(n , vector<bool> (m , false)) ;
    queue<pii> q ;
    if(!fire[Si][Sj])
        q.push(mp(Si , Sj)) ;

    while (q.size()) {
        pii p = q.front() ;
        q.pop() ;

        for(int i = 0 ; i<4 ; i++){
            if(p.F+s[i].F<n && p.F+s[i].F>=0 && p.S+ s[i].S <m && p.S + s[i].S >=0 &&arr[p.F+s[i].F][p.S+ s[i].S ]!='#' && arr[p.F+s[i].F][p.S+ s[i].S ]!='T' ){
                if(arr[p.F+s[i].F][p.S+ s[i].S ]=='G' && !score[p.F+s[i].F][p.S+ s[i].S ]){
                    score[p.F+s[i].F][p.S+ s[i].S ] = true ;
                    ans++ ;
                }
                if(!visited[p.F+s[i].F][p.S+ s[i].S ] && !fire[p.F+s[i].F][p.S+ s[i].S ]){
                    visited[p.F+s[i].F][p.S+ s[i].S ] = true ;
                    q.push(mp(p.F+s[i].F , p.S+ s[i].S)) ;
                }
            }
        }
    }

    cout << ans << nl ;
}



int32_t main(){
    fastio() ;
    int t = 1 ;
    while (t--) {
        solve() ;
    }
    return 0 ;
}
