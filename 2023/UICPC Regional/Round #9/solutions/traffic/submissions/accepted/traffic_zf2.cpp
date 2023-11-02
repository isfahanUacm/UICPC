#include <iostream>

#define MAXN 110000

using namespace std;

int main() {
    int n1, n2, x1, x2, d1 = 0, d2 = 0;
    int t1[MAXN], t2[MAXN];

    cin >> x1 >> x2;
    cin >> n1;
    for (int i = 0; i < n1; ++i) cin >> t1[i];
    cin >> n2;
    for (int i = 0; i < n2; ++i) cin >> t2[i];

    int i1 = 0, i2 = 0;
    for (int t = 1; t <= 3100000; ++t) {
        x1 += d1;
        x2 += d2;
        if (x1 == x2+4 || x2 == x1+4) {
            cout << "bumper tap at time " << t << endl;
            return 0;
        }
        if (i1 < n1 && t == t1[i1]) {
            d1 = 1-d1;
            ++i1;
        }
        if (i2 < n2 && t == t2[i2]) {
            d2 = 1-d2;
            ++i2;
        }
    }
    cout << "safe and sound" << endl;
    return 0;
}
