//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){
    ios_base::sync_with_stdio(false) ;
    string str ;
    cin >> str ;
    int l = str.length() ;
    for(int i=0 ;  i<l-1 ; i++){
        if(str[i]==str[i+1] && str[i]=='s'){
            cout << "hiss\n" ;
            return 0 ;
        }
    }

    cout << "no hiss\n" ;
    return 0 ;
}
