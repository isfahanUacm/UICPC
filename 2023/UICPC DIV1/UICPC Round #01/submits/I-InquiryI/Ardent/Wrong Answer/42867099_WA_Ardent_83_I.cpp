#include <iostream>
#include <math.h>
using namespace std;
int dan(int a){
    if(a-50000<0){
        return 0 ;
    }
    else{
        return a-50000 ;
    }
}
int dan2(int a, int b){
    if(a+50000>b){
        return b ;
    }
    else
        return a+50000 ;
}
int main()
{
    int a[1000000] , sum=0 , gam=2 , mid = 0 , sum2 = 0 , sum1 , i2=0;
    bool tf1 = true ;
    int tedad ;
    cin>>tedad;
    for(int i=0 ; i<tedad ; i++){
        cin>>a[i];
        sum +=a[i];
    }
    mid = sum/3 ;
    for(int i=dan(mid); i<dan2(mid,tedad) ; i++){
        sum1=0 , sum2=0 ;
        for(int j=0 ; j<=i ; j++){
            sum1+= pow(a[j],2);
            if(i2!=0){
                break ;
            }
        }
        for(int j=i+1 ; j<tedad ; j++){
            sum2 += a[j];
        }
        if(tf1){
            sum = sum1 * sum2 ;
            tf1 = false;
        }
        else if(sum1*sum2>sum){
            sum = sum1 * sum2 ;
        }
        else if(sum1*sum2<=sum){
            i2 = i ;
            break ;
        }
    }
    // bedast avardan javab bad az peyda kardan i2
    sum1=0 ; sum2=0 ;
    for(int i=0 ; i<=i2-1 ; i++){
        sum1 +=pow(a[i],2);
    }
    for(int i=i2 ; i<tedad ; i++){
        sum2 += a[i];
    }
    cout<<sum1*sum2<<endl ;



    return 0;
}