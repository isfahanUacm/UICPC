#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {

    int p;
    cin >> p;
    int a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    int ans = 0;
    if (b1 > a1) {
        ans += p - a2;
        a2 = 0;
        a1++;
        ans++;
    }
    if (b1 > a1) {
        ans += b2;
        b2 = p;
        b1--;
        ans++;
    }
    ans += b2 - a2;

    cout << ans << endl;



    return 0;
}
