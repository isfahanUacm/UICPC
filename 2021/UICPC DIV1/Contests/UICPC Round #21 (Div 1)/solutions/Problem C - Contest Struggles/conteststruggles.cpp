#include <bits/stdc++.h>
using namespace std;

// Contest Struggles

int n, k, d, s;

int main() {
    cin >> n >> k >> d >> s;
    double ans = n * d - k * s;
    ans = ans / (n - k);
    if (ans >= 0 && ans <= 100)
        cout << fixed << setprecision(7) << ans << endl;
    else
        cout << "impossible" << endl;
}