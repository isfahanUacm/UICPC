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



void solve(){
    ll ans = 0 ;
    int x , y ;
    cin >> x >> y ;
    int vx = 1 , vy = 1 ;
    vector<vector<char>> arr(x , vector<char>( y , '.')) ;
    for(int i = 0;  i<x ; i)
        for(int j=0 ; j<y ; j){
            if(arr[i][j]=='.'){
                ans++ ;
                arr[i][j] = '+' ;
            }
            if((i==x-1 || i==0) && (j == y-1 || j==0) && !(i==0 && j==0)){
                cout << ans << nl ;
                return;
            }
            if(!(i + vx<x && i + vx>=0))
                vx *= -1 ;
            if(!(j + vy<y && j+vy>=0))
                vy *= -1 ;
            i += vx ;
            j += vy ;
        }

}



int32_t main(){
    fastio() ;
    int t = 1 ;
    cin >> t ;
    while (t--) {
        solve() ;
    }
    return 0 ;
}
