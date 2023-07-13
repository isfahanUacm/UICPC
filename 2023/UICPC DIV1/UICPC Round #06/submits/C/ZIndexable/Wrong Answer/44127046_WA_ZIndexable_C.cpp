#include "bits/stdc++.h"

using namespace std;
//const double epsilon = 0.000000000001f; // tolerance level
long x1, x2, Y1, Y2;
long is_exact(double c) {
    if (c == round(c)) {
        return (long)round(c);
    } else {
        return -1L;
    }
}

int main() {
    long x, y;
    cin >> x >> y;
    cin >> x1 >> Y1 >> x2 >> Y2;
    double a = (double)y / x;

    long x_unit;
    long y_unit;
    for (long i = 1; i < x; ++i) {
        double n = i * a;

        long tmp_y = is_exact(n);
        if (tmp_y != -1){
            x_unit = i;
            y_unit = tmp_y;
            break;
        }
    }
    long cur_y = y_unit, cur_x= x_unit;
    long cof = 1;
    while (y > cur_y && x > cur_x) {
        if (x1 <= cur_x && cur_x <= x2){
            if (Y1 <= cur_y && cur_y <= Y2) {
                cof++;
                cur_x = x_unit * cof;
                cur_y = y_unit * cof;
                continue;
            }
        }
        cout << "No" << endl;
        cout << cur_x << " " << cur_y;
        exit(0);
    }

    cout << "Yes";
    return 0;
}
