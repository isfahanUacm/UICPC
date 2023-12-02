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
    ll a , b , c, d ;
    cin >> a >> b >> c >>d ;
    if(a == 0 && b==0 && c==0 && d==0){
        cout << '0' << nl ;
        return;
    }
    if(a == 0 && b==0 && c==0 && d==0){
        cout << '0' << nl ;
        return;
    }
    if(a == 0 && b==0 && c==0 && d==0){
        cout << '0' << nl ;
        return;
    }
    if(a == 0 && b==0 && c==0 && d==0){
        cout << '0' << nl ;
        return;
    }

    ll n = sqrt(2*a) ;
    n++ ;
    if(n * (n-1)/2 != a){
        cout << "impossible" << nl ;
        return;
    }

    ll m = sqrt(2*d) ;

    m++ ;
    if(m * (m-1)/2 != d){
        cout << "impossible" << nl ;
        return;
    }
    if(a == 0){
        n = 0 ;
    }
    if(d == 0){
        m  = 0 ;
    }
    if(!(a ==0 || d==0 || b + c == n * m)){
        cout << "impossible" << nl ;
        return;
    }
    else if(a == 0 && b == 0){
        if(b+c > 1){
            cout << "impossible" << nl ;
            return;
        }
        else if(b ==1){
            cout << "01" ;
        }
        else{
            cout << "10" ;
        }
        return;
    }
    else if(a == 0 && b+c != 0){
        if(b + c != m){
            cout << "impossible" << nl ;
            return;
        }
        FOR(i , 0 , c)
                cout << 1 ;
        cout << 0 ;
        FOR(i , c , m)
                cout << 1  ;
        return;
    }
    else if(d == 0 && b+c != 0){
        if(b + c != n){
            cout << "impossible" << nl ;
            return;
        }
        FOR(i , 0 , b)
                cout << 0 ;
        cout << 1 ;
        FOR(i , c , n)
                cout << 0 ;
        return;
    }

    char arr[n+m] ;

    FOR(i , 0 , n){
        arr[i] = '0' ;
    }

    FOR(i , 0 , m){
        arr[i+ n] = '1' ;
    }
    ll ted = 0 ;
    FOR(i , n , n+m){
        if(ted + n <= c){
            swap(arr[i-n] , arr[i]) ;
            ted += n ;
        }
        else{
            swap(arr[i] , arr[i-(c - ted)]) ;
            break;
        }
    }

    FOR(i , 0 , n+m){
        cout << arr[i] ;
    }

    cout << nl ;
}




int32_t main(){
    fastio() ;
    int t = 1 ;
  //  cin >> t ;
    while (t--) {
        solve() ;
    }
    return 0 ;
}
