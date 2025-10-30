#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    int n , m ;
    cin >> n >> m ;
    if(n+1 <= m)cout << n+1;
    else if(m == n)cout << n;
    else cout << 0;

    return 0;
}