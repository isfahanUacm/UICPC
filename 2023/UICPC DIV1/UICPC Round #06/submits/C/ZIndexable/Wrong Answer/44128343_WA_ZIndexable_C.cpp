#include "bits/stdc++.h"

using namespace std;
long x1, x2, Y1, Y2;
const float epsilon = 0.000000000001f;
long is_exact(double c) {
    if (fabs(c - round(c)) <= epsilon) {
        return (long)round(c);
    } else {
        return -1L;
    }
}

long last_point(double a) {
    double temp_y = a * x2;
    if (Y1 <= temp_y && temp_y <= Y2)
        return x2;
    double temp_x = Y2 / a;
    if (x1 <= temp_x && temp_x <= x2)
        return floor(temp_x);

    else return -1;
}

int main() {
    double x, y;
    cin >> x >> y;
    cin >> x1 >> Y1 >> x2 >> Y2;

    double a = y / x;
    for (long i = 1; i < x; ++i) {
        double n = i * a;

        long tmp_y = is_exact(n);
        if (tmp_y == -1)
            continue;
        if (x1 <= i && i <= x2){
            if (Y1 <= tmp_y && tmp_y <= Y2) {
                i = last_point(a);
                continue;
            }
        }
        cout << "No" << endl;
        cout << i << " " << tmp_y;
        exit(0);
    }

    cout << "Yes";
    return 0;
}