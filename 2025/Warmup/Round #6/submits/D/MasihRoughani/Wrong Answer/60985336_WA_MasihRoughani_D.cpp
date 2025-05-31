#include <iostream>
#include <cmath>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        ll r, k;
        ll n;
        cin >> r >> k;
        if (r % k == 0) n = r - 1;
        else n = r;
        ll max = 0;
        while (n != 0) {
            if (n % k == 0) {
                n = n / k;
                max++;
            } else {
                n--;
                max++;
            }
        }
        cout << max << "\n";
    }
    return 0;
}
