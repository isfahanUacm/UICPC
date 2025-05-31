#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int b ;
        cin >> b;
        int sum = 0 ;
        for(int j = 0 ; j < b ; j++){
            int y ;
            cin >> y ;
            sum += y ;
        }
        if(sum %2 == 0){
            cout  << b << endl ;
        }else cout << 0 ;
    }
}
