#include <iostream>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    ll n, m, tot = 0;
    cin >> n >> m;

    ll excess = m-(n-1);

    for (ll j = 1, k = 1; j <= m; ++j, ++k) {
        tot += j;
        if (excess > 0) {
            j += min(excess, k-1);
            excess -= k-1;
        }
        else {
            tot += (m*(m+1) - j*(j+1))/2;
            break;
        }
    }

    cout << tot << endl;

    return 0;
}
