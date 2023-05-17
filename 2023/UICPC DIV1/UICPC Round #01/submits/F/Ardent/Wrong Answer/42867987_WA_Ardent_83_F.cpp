#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int n , a1 , a2 , b1 , b2;
    bool tf = false ;
    cin>>n ;
    for(int i=1 ; i<=n ; i++){
        if(n%i==0){
            a1 = i ;
            a2 = n/i ;
            b1 = (a1+a2)/2 ;
            b2 = n - b1 ;
            if(abs(pow(b1,2)-pow(b2,2))==n){
                tf = true ;
                break ;
            }
        }
    }
    if(tf == true){
        if(b1>b2){
            cout<<b1<<" "<<b2<<endl ;
        }
        else{
            cout<<b2<<" "<<b1<<endl ;
        }
    }
    else{
        cout<<"impossible" << endl;
    }
    return 0;
}
