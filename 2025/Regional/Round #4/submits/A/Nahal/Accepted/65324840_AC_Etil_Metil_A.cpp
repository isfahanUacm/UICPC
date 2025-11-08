#include <bits/stdc++.h>

using namespace std;

int main() {
    int r, g, b;
    cin >> r >> g >> b;
    int c_r, c_g, c_b;
    cin >> c_r >> c_g >> c_b;
    int c_rg, c_gb;
    cin >> c_rg >> c_gb;
    int red = r - c_r;
    if (red < 0) {
        red = 0;
    }
    int green = g - c_g;
    if (green < 0) {
        green = 0;
    }
    int blue = b - c_b;
    if (blue < 0) {
        blue = 0;
    }
    int sum1 = c_rg + c_gb;
    int sum2 = red + green + blue;
    if (sum1 < sum2) {
        cout << -1;
        return 0;
    } else {
        if (blue == c_gb && red + green > c_rg) {
            cout << -1;
            return 0;
        }
        if (red == c_rg && green + blue > c_gb) {
            cout << -1;
            return 0;
        }

        if (red > c_rg) {
            cout << -1;
            return 0;
        }
        if (blue > c_gb) {
            cout << -1;
            return 0;
        } else {
            cout << sum2;
        }
    }

    return 0;
}
