#include <iostream>
using namespace std;

int main() {
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int q , w ;
        cin >> q >> w ;
        cout << (q + w )/2 << " " <<( q-w)/2<<endl ;
    }
}
