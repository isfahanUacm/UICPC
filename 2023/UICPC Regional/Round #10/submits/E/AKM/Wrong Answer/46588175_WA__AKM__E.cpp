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
    int n;
    cin >> n ;
    string a , b ;
    cin >> a >> b ;

    vector<int> arr1 ;
    vector<int> arr2 ;
    bool test = true ;
    if(n % 2 == 0 ){
        FOR(i , 0 , n/2){
            if(a[i] != b[i]){
                test = false ;
                break;
            }
        }

        if(test){
            FOR(i , 0 , n/2){
                cout << a[i] ;
            }

            cout << nl ;
            return;
        }

        test = true ;

        FOR(i , n/2 , n){
            if(a[i] != b[i]){
                test = false ;
                break;
            }
        }

        if(test){
            FOR(i , n/2 , n){
                cout << a[i] ;
            }

            cout << nl ;
            return;
        }

    }
    FOR(i , 0 , n) {
        if(a[i] == 'A')
            arr1.pb(i) ;



        if(b[i] == 'A')
            arr2.pb(i) ;

    }

    int q1 = arr1.size() ;
    int q2 = arr2.size() ;

    pii ans = {0 , n-1};
    int last = 0 ;
    int ia = 0  , ib = 0  , t1 , t2;
    test = true ;
    while (ia !=q1 && ib !=q2) {
        if(test){
            if(min(arr1[ia] , arr2[ib])>= n/2 && arr1[ia] != arr2[ib]){
                ans = {0 , min(arr1[ia] , arr2[ib])-1} ;
            }
            test = false ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] < arr2[ib]) {
            last = arr1[ia] + 1 ;
            ia++ ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] > arr2[ib]) {
            last = arr2[ib] + 1 ;
            ib++ ;
        }
        t1 = last ;
        while (ia < q1 && ib< q2 && arr1[ia] == arr2[ib]) {
            if(!(ia < q1 && ib< q2 && arr1[ia+1] == arr2[ib+1])){

                if(!(ia < q1 && ib< q2))
                {
                    t2 = n - 1 ;
                }
                else{
                    t2 = min(arr1[ia+1],arr2[ib+1]) - 1 ;
                }
                if(t2 - t1 + 1 >= n/2){
                    ans = {t1 , t2} ;
                    break;
                }
            }
            ia++;
            ib++ ;
        }
    }
    if(ia == q1 && ib != q2){
        if(q1 == 0)
            arr1.push_back(-1) ;
        if(arr2[ib]-arr1[ia-1] >= n/2){
            ans = {arr1[ia-1]+1  , arr2[ib]-1} ;
        }
    }
    else if(ia != q1 && ib == q2){
        if(q2 == 0)
            arr2.push_back(-1) ;
        if(arr1[ia]-arr2[ib-1] >= n/2){
            ans = {arr2[ib-1]+1  , arr1[ia]-1} ;
        }
    }
    if(q1>0 && q2>0){
        if(max(arr1[q1-1] , arr2[q2-1]) < n/2){
            ans = {max(arr1[q1-1] , arr2[q2-1])+1 , n-1} ;
        }
    }
    else if(q1>0){
        if(arr1[q1-1] < n/2){
            ans = {arr1[q1-1]+1 , n-1} ;
        }
    }
    else if(q2>0){
        if(arr2[q2-1] < n/2){
            ans = {arr2[q2-1]+1 , n-1} ;
        }
    }

    arr1.clear() ;
    arr2.clear() ;

    FOR(i , ans.F , ans.S+1) {
        if(a[i] == 'C')
            arr1.pb(i) ;



        if(b[i] == 'C')
            arr2.pb(i) ;

    }

    q1 = arr1.size() ;
    q2 = arr2.size() ;

    last = ans.F ;
    ia = 0  , ib = 0  ;
    test = true ;
    while (ia !=q1 && ib !=q2) {
        if(test){
            if(min(arr1[ia] , arr2[ib])>= n/2 && arr1[ia] != arr2[ib]){
                ans = {0 , min(arr1[ia] , arr2[ib])-1} ;
            }
            test = false ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] < arr2[ib]) {
            last = arr1[ia] + 1 ;
            ia++ ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] > arr2[ib]) {
            last = arr2[ib] + 1 ;
            ib++ ;
        }
        t1 = last ;
        while (ia < q1 && ib< q2 && arr1[ia] == arr2[ib]) {
            if(!(ia < q1 && ib< q2 && arr1[ia+1] == arr2[ib+1])){

                if(!(ia < q1 && ib< q2))
                {
                    t2 = n - 1 ;
                }
                else{
                    t2 = min(arr1[ia+1],arr2[ib+1]) - 1 ;
                }
                if(t2 - t1 + 1 >= n/2){
                    ans = {t1 , t2} ;
                    break;
                }
            }
            ia++;
            ib++ ;
        }
    }
    if(ia == q1 && ib != q2){
        if(q1 == 0)
            arr1.push_back(-1) ;
        if(arr2[ib]-arr1[ia-1] >= n/2){
            ans = {arr1[ia-1]+1  , arr2[ib]-1} ;
        }
    }
    else if(ia != q1 && ib == q2){
        if(q2 == 0)
            arr2.push_back(-1) ;
        if(arr1[ia]-arr2[ib-1] >= n/2){
            ans = {arr2[ib-1]+1  , arr1[ia]-1} ;
        }
    }
    if(q1>0 && q2>0){
        if(max(arr1[q1-1] , arr2[q2-1]) < n/2){
            ans = {max(arr1[q1-1] , arr2[q2-1])+1 , n-1} ;
        }
    }
    else if(q1>0){
        if(arr1[q1-1] < n/2){
            ans = {arr1[q1-1]+1 , n-1} ;
        }
    }
    else if(q2>0){
        if(arr2[q2-1] < n/2){
            ans = {arr2[q2-1]+1 , n-1} ;
        }
    }
    arr1.clear() ;
    arr2.clear() ;

    FOR(i , ans.F , ans.S+1) {
        if(a[i] == 'G')
            arr1.pb(i) ;



        if(b[i] == 'G')
            arr2.pb(i) ;

    }

    q1 = arr1.size() ;
    q2 = arr2.size() ;

    last = ans.F ;
    ia = 0  , ib = 0  ;
    test = true ;
    while (ia !=q1 && ib !=q2) {
        if(test){
            if(min(arr1[ia] , arr2[ib])>= n/2 && arr1[ia] != arr2[ib]){
                ans = {0 , min(arr1[ia] , arr2[ib])-1} ;
            }
            test = false ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] < arr2[ib]) {
            last = arr1[ia] + 1 ;
            ia++ ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] > arr2[ib]) {
            last = arr2[ib] + 1 ;
            ib++ ;
        }
        t1 = last ;
        while (ia < q1 && ib< q2 && arr1[ia] == arr2[ib]) {
            if(!(ia < q1 && ib< q2 && arr1[ia+1] == arr2[ib+1])){

                if(!(ia < q1 && ib< q2))
                {
                    t2 = n - 1 ;
                }
                else{
                    t2 = min(arr1[ia+1],arr2[ib+1]) - 1 ;
                }
                if(t2 - t1 + 1 >= n/2){
                    ans = {t1 , t2} ;
                    break;
                }
            }
            ia++;
            ib++ ;
        }
    }
    if(ia == q1 && ib != q2){
        if(q1 == 0)
            arr1.push_back(-1) ;
        if(arr2[ib]-arr1[ia-1] >= n/2){
            ans = {arr1[ia-1]+1  , arr2[ib]-1} ;
        }
    }
    else if(ia != q1 && ib == q2){
        if(q2 == 0)
            arr2.push_back(-1) ;
        if(arr1[ia]-arr2[ib-1] >= n/2){
            ans = {arr2[ib-1]+1  , arr1[ia]-1} ;
        }
    }
    if(q1>0 && q2>0){
        if(max(arr1[q1-1] , arr2[q2-1]) < n/2){
            ans = {max(arr1[q1-1] , arr2[q2-1])+1 , n-1} ;
        }
    }
    else if(q1>0){
        if(arr1[q1-1] < n/2){
            ans = {arr1[q1-1]+1 , n-1} ;
        }
    }
    else if(q2>0){
        if(arr2[q2-1] < n/2){
            ans = {arr2[q2-1]+1 , n-1} ;
        }
    }

    arr1.clear() ;
    arr2.clear() ;

    FOR(i , ans.F , ans.S+1) {
        if(a[i] == 'T')
            arr1.pb(i) ;



        if(b[i] == 'T')
            arr2.pb(i) ;

    }

    q1 = arr1.size() ;
    q2 = arr2.size() ;

    last = ans.F ;
    ia = 0  , ib = 0  ;
    test = true ;
    while (ia !=q1 && ib !=q2) {
        if(test){
            if(min(arr1[ia] , arr2[ib])>= n/2 && arr1[ia] != arr2[ib]){
                ans = {0 , min(arr1[ia] , arr2[ib])-1} ;
            }
            test = false ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] < arr2[ib]) {
            last = arr1[ia] + 1 ;
            ia++ ;
        }
        while (ia < q1 && ib< q2 && arr1[ia] > arr2[ib]) {
            last = arr2[ib] + 1 ;
            ib++ ;
        }
        t1 = last ;
        while (ia < q1 && ib< q2 && arr1[ia] == arr2[ib]) {
            if(!(ia < q1 && ib< q2 && arr1[ia+1] == arr2[ib+1])){

                if(!(ia < q1 && ib< q2))
                {
                    t2 = n - 1 ;
                }
                else{
                    t2 = min(arr1[ia+1],arr2[ib+1]) - 1 ;
                }
                if(t2 - t1 + 1 >= n/2){
                    ans = {t1 , t2} ;
                    break;
                }
            }
            ia++;
            ib++ ;
        }
    }
    if(ia == q1 && ib != q2){
        if(q1 == 0)
            arr1.push_back(-1) ;
        if(arr2[ib]-arr1[ia-1] >= n/2){
            ans = {arr1[ia-1]+1  , arr2[ib]-1} ;
        }
    }
    else if(ia != q1 && ib == q2){
        if(q2 == 0)
            arr2.push_back(-1) ;
        if(arr1[ia]-arr2[ib-1] >= n/2){
            ans = {arr2[ib-1]+1  , arr1[ia]-1} ;
        }
    }
    if(q1>0 && q2>0){
        if(max(arr1[q1-1] , arr2[q2-1]) < n/2){
            ans = {max(arr1[q1-1] , arr2[q2-1])+1 , n-1} ;
        }
    }
    else if(q1>0){
        if(arr1[q1-1] < n/2){
            ans = {arr1[q1-1]+1 , n-1} ;
        }
    }
    else if(q2>0){
        if(arr2[q2-1] < n/2){
            ans = {arr2[q2-1]+1 , n-1} ;
        }
    }

    FOR(i , ans.F , ans.S+1) cout << a[ans.F] ;

    cout << nl ;

}



int32_t main(){
    fastio() ;
    int t = 1 ;

    while (t--) {
        solve() ;
    }
    return 0 ;
}

