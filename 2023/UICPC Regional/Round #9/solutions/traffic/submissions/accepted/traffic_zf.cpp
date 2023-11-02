#include <iostream>
#include <algorithm>

using namespace std;

int aa[100000], bb[100000];

int main() {
    int x1, x2, n1, n2;
    int *a = aa, *b = bb;
    cin >> x1 >> x2;

    cin >> n1;
    for (int i = 0; i < n1; ++i) cin >> a[i];

    cin >> n2;
    for (int i = 0; i < n2; ++i) cin >> b[i];

    if (x1 > x2) {
        swap(x1, x2);
        swap(n1, n2);
        swap(a, b);
    }

    int i = 0, j = 0, d1 = 0, d2 = 0, t = 0, dt;

    while (i < n1 || j < n2) {
        bool first = (j == n2 || (i < n1 && a[i] < b[j]));

        dt = (first ? a[i]-t : b[j]-t);
        int nx1 = x1+dt*d1, nx2 = x2+dt*d2;

        if (nx1 + 5 > nx2) {
            cout << "bumper tap at time " << x2-x1-4+t << endl;
            return 0;
        }

        x1 = nx1;
        x2 = nx2;

        if (first) { d1 = 1-d1; ++i; }
        else       { d2 = 1-d2; ++j; }

        t += dt;
    }

    if (d1 == 1 && d2 == 0) cout << "bumper tap at time " << x2-x1-4+t << endl;
    else cout << "safe and sound" << endl;
    return 0;
}
