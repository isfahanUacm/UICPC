//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;


int main(void){
    ios_base::sync_with_stdio(false) ;
    int n ;
    set<string> s;
    string temp ;
    string a , b ;
    int t ;
    int l ;
    cin >> t ;
    bool test ;
    for(int j=0 ; j<t ; j++){
        test = false ;
        s.clear() ;
        cin >> n ;
        for(int i = 0 ; i<n;  i++){
            cin >> temp ;
            s.insert(temp) ;
        }

        a = *s.begin() ;
        s.erase(*s.begin()) ;
        while (!s.empty()) {
            l = 0 ;
            b = *s.begin() ;
            s.erase(*s.begin()) ;

            while (l<a.length() && a[l]==b[l])
                l++ ;

            if(l==a.length()){
                test = true ;
                break;
            }
            a = b ;
        }

        if(test)
            cout << "NO\n" ;
        else
            cout << "YES\n" ;

    }


    return 0 ;
}

