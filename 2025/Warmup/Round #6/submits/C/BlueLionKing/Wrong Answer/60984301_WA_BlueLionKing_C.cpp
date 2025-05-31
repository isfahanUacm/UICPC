#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int  n ;
    cin >> n ;
    for(long long int i = 0 ; i < n ; i++){
        long long int o , p ;
        cin >> o >> p ;
        if(o == p){
            cout << 0 << endl ;
            continue;
        }
        int d = 0 ;
        long long int q = ceil(sqrt(o));
        if(q*q == o)d++;
        long long int w = floor(sqrt(p));
        if(w*w == p)d++;
        if(q > w){
            cout << 0 << endl ;
            continue;
        }
//        cout << q << endl << w << d ;
        cout << max(0LL , (abs(q-w)+1)-d) << endl ;
    }
}
