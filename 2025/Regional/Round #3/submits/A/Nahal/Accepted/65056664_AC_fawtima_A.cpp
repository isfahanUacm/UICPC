#include <bits/stdc++.h>
using namespace std;


int main() {
    long double n;
    cin >> n;
    long double a, O;
    cin >> a >> O;
    long double da, dO;
    cin >> da >> dO;
    long double temp = a - (n * da);
    if (temp <= 0) {
        cout << 0 << endl;
        return 0;
    }
    long double m = temp + O - n * dO;
    if (m - temp <= 0) {
        cout << 100 << endl;
        return 0;
    }
    long double b = (temp / m) * 100;
    if (b < 10) {
        cout << fixed << setprecision(14) << b << endl;
    } else {
        cout << fixed << setprecision(13) << b << endl;
    }

    return 0;
}
