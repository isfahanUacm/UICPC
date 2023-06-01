//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;


int main(void){
    int n ;
    cin >> n ;
    string str[n] ;
    int ky = 0 , kn = 0  ;
    for(int i=0 ; i<n ; i++){
        cin >> str[i] ;
        if(str[i][0]=='Y')
            ky++ ;
        else
            kn++ ;
    }
    double answer ;
    int a = 0 , b = 0 ;
    for(int j=1 ; j<4 ; j++){
        a = 0 ;
        b = 0 ;
        for(int i=0 ; i<n ; i++){
            if(str[i][0]=='Y'&& str[i][j]=='Y')
                a ++ ;
            else if(str[i][0]=='N'&& str[i][j]=='Y')
                b++ ;

        }
        a *= kn ;
        b *= ky ;
        answer = double(a)/double(b) ;
        if(a>=b){
            cout << "Not Effective" << '\n' ;
        }
        else{
            answer = 1 - answer ;
            answer *= 100 ;
            printf("%.2f",answer) ;
            printf("\n") ;
        }
    }
    return 0 ;
}
