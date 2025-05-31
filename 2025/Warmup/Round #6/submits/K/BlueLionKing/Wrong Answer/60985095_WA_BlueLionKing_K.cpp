#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
    int n , t , k , d ;
    cin >> n >> t >> k >> d ;
    int q = floor(n/k) * t ;
    int w = d + (floor(n/(2*k))*t);
    if(w <= q)cout << "YES";
    else cout << "NO";
}
