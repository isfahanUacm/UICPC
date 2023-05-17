#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double n, k;
    double a = 0;
    cin >> n >> k;

    for (auto i = 0; i < k; i++) {
        auto h = floor(a);
        auto f = h / n;
        a = f * a + (1 - f) * ((h + n + 1) / 2);
    }

    cout << setprecision(9) << a << endl;

    return 0;
}
