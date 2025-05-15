#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {

    ll p;
    cin >> p;
    ll a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;


    ll ans = ((b1 * (p + 1)) + b2) - ((a1 * (p + 1)) + a2);

    cout << ans << endl;

    // int n ;
    // cin >> n ;
    // in =t

    return 0;
}
