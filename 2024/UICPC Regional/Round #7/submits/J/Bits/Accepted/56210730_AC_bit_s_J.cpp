#include <iostream>
using namespace std;

int main() {
    int t ; cin >> t ;
    int sum = 0 ;
    for(int i = 0 ; i < t; i ++)
    {
        char c ;
        int n ;
        cin >> c ; cin >> n ;
        if( c == 'P')
            sum += n ;
        else
            if(sum < n){
                cout<<"YES\n";
                sum =0 ;
            }else
            {
                cout<<"NO\n";
                sum -= n;
            }
    }

    return 0;
}