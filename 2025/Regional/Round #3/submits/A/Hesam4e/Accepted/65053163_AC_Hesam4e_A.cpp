#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    long double n, q, w, e, r;
    cin >> n >> q >> w >> e >> r;
    long double g = q - (n * e);
    long double f = w - (n * r);
    if (g < 0)
        g = 0;
    if (f < 0)
        f = 0;
    long double p = g / (g + f) * 100;

    cout << fixed << setprecision(14) << p;
    return 0;
}