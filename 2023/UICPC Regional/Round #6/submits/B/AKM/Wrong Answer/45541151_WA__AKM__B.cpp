//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

#define fastio() ios_base::sync_with_stdio(false) ; cin.tie(NULL) ; cout.tie(NULL) ;
#define MOD 1000000007
#define MOD1 998244353
#define LL_INF 1e18 + 100
#define INT_INF 1e9 + 10
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
    int n , m ;
    cin >> n >> m;
    int a1i , a1j , a2i , a2j , b1i , b1j , b2i , b2j , s1 , s2;
    cin >> a1i >> a1j >> a2i >> a2j >> b1i >> b1j >> b2i >> b2j ;
    ll ans = 0 ;
    if(a1j>a2j){
        swap(a1i , a2i) ;
        swap(a1j , a2j) ;
    }

    if(b1j>b2j){
        swap(b1j , b2j) ;
        swap(b1i , b2i) ;
    }

    if(a1j<b1j && b2j<a2j){
        ans = b2j - b1j ;
        ans += abs(b2i-b1i) ;
        if(max(b1i , b2i)==n && min(b1i , b2i)==0){
            cout << "IMPOSSIBLE\n" ;
            return;
        }
        ans += a2j - a1j ;
        ans += abs(a2i-a1i) ;
        s1 = INT_INF  ;
        s2 = INT_INF ;
        if(max(b1i , b2i)!=n){
            s1 = max(b1i , b2i) - max(a1i , a2i) ;
            s1++ ;
            if(s1<0) s1 = 0 ;
        }
        if(min(b1i , b2i)!=0){
            s2 = min(a1i , a2i) - min(b1i , b2i)  ;
            s2++ ;
            if(s2<0) s2 = 0 ;
        }
        ans += 2 * min(s1 , s2) ;
        cout << ans << nl ;
        return;
    }

    swap(a1i , b1i ) ;
    swap(a1j , b1j ) ;
    swap(a2i , b2i ) ;
    swap(a2j , b2j ) ;

    if(a1j<b1j && b2j<a2j){
        ans = b2j - b1j ;
        ans += abs(b2i-b1i) ;
        if(max(b1i , b2i)==n && min(b1i , b2i)==0){
            cout << "IMPOSSIBLE\n" ;
            return;
        }
        ans += a2j - a1j ;
        ans += abs(a2i-a1i) ;
        s1 = INT_INF  ;
        s2 = INT_INF ;
        if(max(b1i , b2i)!=n){
            s1 = max(b1i , b2i) - max(a1i , a2i) ;
            s1++ ;
            if(s1<0) s1 = 0 ;
        }
        if(min(b1i , b2i)!=0){
            s2 = min(a1i , a2i) - min(b1i , b2i)  ;
            s2++ ;
            if(s2<0) s2 = 0 ;
        }
        ans += 2*min(s1 , s2) ;
        cout << ans << nl ;
        return;
    }

    swap(a1i , a1j ) ;
    swap(a2i , a2j ) ;
    swap(b1i , b1j ) ;
    swap(b2i , b2j ) ;
    swap(n , m) ;

    if(a1j<b1j && b2j<a2j){
        ans = b2j - b1j ;
        ans += abs(b2i-b1i) ;
        if(max(b1i , b2i)==n && min(b1i , b2i)==0){
            cout << "IMPOSSIBLE\n" ;
            return;
        }
        ans += a2j - a1j ;
        ans += abs(a2i-a1i) ;
        s1 = INT_INF  ;
        s2 = INT_INF ;
        if(max(b1i , b2i)!=n){
            s1 = max(b1i , b2i) - max(a1i , a2i) ;
            s1++ ;
            if(s1<0) s1 = 0 ;
        }
        if(min(b1i , b2i)!=0){
            s2 = min(a1i , a2i) - min(b1i , b2i)  ;
            s2++ ;
            if(s2<0) s2 = 0 ;
        }
        ans += 2* min(s1 , s2) ;
        cout << ans << nl ;
        return;
    }


    swap(a1i , b1i ) ;
    swap(a1j , b1j ) ;
    swap(a2i , b2i ) ;
    swap(a2j , b2j ) ;

    if(a1j<b1j && b2j<a2j){
        ans = b2j - b1j ;
        ans += abs(b2i-b1i) ;
        if(max(b1i , b2i)==n && min(b1i , b2i)==0){
            cout << "IMPOSSIBLE\n" ;
            return;
        }
        ans += a2j - a1j ;
        ans += abs(a2i-a1i) ;
        s1 = INT_INF  ;
        s2 = INT_INF ;
        if(max(b1i , b2i)!=n){
            s1 = max(b1i , b2i) - max(a1i , a2i) ;
            s1++ ;
            if(s1<0) s1 = 0 ;
        }
        if(min(b1i , b2i)!=0){
            s2 = min(a1i , a2i) - min(b1i , b2i)  ;
            s2++ ;
            if(s2<0) s2 = 0 ;
        }
        ans += 2 * min(s1 , s2) ;
        cout << ans << nl ;
        return;
    }

    ans = abs(a1i - a2i) + abs(a1j - a2j) + abs(b1i - b2i) + abs(b1j - b2j) ;
}



int32_t main(){
    fastio() ;
    int t = 1 ;

    while (t--) {
        solve() ;
    }
    return 0 ;
}
