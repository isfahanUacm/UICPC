//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    int n;

    string num ;
    cin >> n ;
    for(int i=0 ; i<n;  i++){
        cin >> num ;
        for(int i=0 ; i<6 ; i++){
            if(num[i]<num[5-i])
                cout << num[i] ;
            else
                cout << num[5-i] ;
        }

        cout << '\n' ;

    }
    return 0 ;
}
