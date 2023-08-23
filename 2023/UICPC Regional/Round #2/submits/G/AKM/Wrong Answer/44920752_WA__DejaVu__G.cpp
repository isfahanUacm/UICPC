//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;


int main(void){
    ios_base::sync_with_stdio(false) ;
    int t  , n , a , b ;
    bool add ;
    pair<int,int> p ;
    cin >> t ;
    int c , d ;
    for(int i = 0 ; i<t ; i++){
        set<pair<int,int>> arr ;
        set<pair<int,int>> arr2 ;
        set<pair<int,int>> arr3 ;
        cin >> n ;


        for(int j = 0 ; j<n; j++){
            cin >> a >> b ;
            arr.insert(make_pair(-a , -b )) ;
        }

        for(auto v : arr){
            add = false ;
            a = -v.first ;
            b = -v.second ;

            for(auto u : arr2){
                c = -u.first ;
                d = -u.second ;
                if(!add && a<c && b < d){
                    p = make_pair(-a , -b) ;
                    arr3.insert(p) ;
                    add = true ;

                }
                else
                    arr3.insert(u) ;

            }

            if(!add){
                arr2.insert(make_pair(-a , -b)) ;
                arr3.clear() ;
            }
            else{
                arr2.clear() ;
                for(auto u : arr3)
                    arr2.insert(u) ;

                arr3.clear() ;
            }



        }

        cout << arr2.size() << '\n' ;
    }

    return 0 ;
}

