#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    double n, q, w, e, r;
    cin >> n >> q >> w >> e >> r;
    double g = q - (n * e);
    double f = w - (n * r);
    double p = g / (g + f);

    cout << fixed << setprecision(14) << p * 100;
    return 0;
}