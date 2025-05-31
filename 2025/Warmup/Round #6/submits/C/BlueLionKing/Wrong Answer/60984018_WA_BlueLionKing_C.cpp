#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int  n ;
    cin >> n ;
    for(long long int i = 0 ; i < n ; i++){
        long long int o , p ;
        cin >> o >> p ;
        long long int q = ceil(sqrt(o));
        long long int w = floor(sqrt(p));
        cout << max(0LL , abs(q-w)+1) << endl ;
    }
}
