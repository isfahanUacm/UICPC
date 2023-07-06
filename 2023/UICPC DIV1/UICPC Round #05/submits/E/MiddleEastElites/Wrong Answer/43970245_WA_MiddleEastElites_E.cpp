//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    int n;
    cin >> n ;
    int test ;
    string good[n] ;
    int g = 0 ;
    string str[n] ;
    string temp ;
    for(int i=0 ; i<n ; i++){
        cin >> temp ;
        str[i] = temp ;
        test  = true ;
        for(int j=0 ; j<3 ; j++){
            if(temp[j]!=temp[5-j]){
                test = false ;
                break;
            }
        }

        if(test){
            good[g++] = str[i] ;
        }
    }
    ll tt ;
    ll mz ;

    if(g==0){
        for(int i= 0 ; i<n;  i++){
            cout << str[i] << '\n' ;
        }
        return 0;
    }


    for(int i=0 ; i<n;  i++){
        mz = 1e18 ;
        for(int j=0 ; j<g ; j++){
            tt = 0 ;
            for(int k= 0  ; k<6 ; k++){
                tt += abs(str[i][k]-good[j][k]) ;
            }

            if(mz>tt){
                mz = tt ;
                temp = good[j] ;
            }

        }
        cout << temp << '\n' ;
    }

    return 0 ;
}
