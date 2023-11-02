#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int n;
double a[10], b[10], c[10], mu[10], x[10], t;

bool ok(double xx) {
    double tt = 0;
    for (int i = 0; i < n; ++i) {
        //mu[i] = max(0.0, xx-b[i]);
        //x[i] = (xx-b[i]-mu[i])/(2*a[i]);
        //tt += x[i];

        x[i] = max(0.0, (xx-b[i])/(2*a[i]));
        tt += x[i];
    }

    return tt <= t;
}

int main() {
    cin >> n >> t;
    for (int i = 0; i < n; ++i) cin >> a[i] >> b[i] >> c[i];

    double lo = -1000, hi = 1000;
    while (!ok(hi)) hi *= 2; // maybe not necessary
    while (ok(lo)) lo *= 2;  // same here

    while (lo + 1e-12 < hi) {
        double mid = (lo+hi)*0.5;
        if (!ok(mid)) lo = mid;
        else hi = mid;
    }

    double val = 0;
    for (int i = 0; i < n; ++i) val += a[i]*x[i]*x[i] + b[i]*x[i] + c[i];
    cout.setf(ios::fixed);
    cout.precision(10);
    cout << val/n << endl;
}
