#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int a, b, c;
    cin >> a;
    cin >> b;
    c = a*b;
    if (a < 0) {
        a = 128;
    }
    else if (a < 2147483648) {
        a = 32;
    }
    else if (a < 9223372036854775808) {
        a = 64;
    }
    else {
        a = 128;
    }
    if (b < 0) {
        b = 128;
    }
    else if (b < 2147483648) {
        b = 32;
    }
    else if (b < 9223372036854775808) {
        b = 64;
    }
    else {
        b = 128;
    }

    if (c < 0) {
        c = 128;
    }
    else if (c < 2147483648) {
        c = 32;
    }
    else if (c < 9223372036854775808) {
        c = 64;
    }
    else {
        c = 128;
    }

    if (c == 128 && b == 64 && a == 32) {
        b = 128;
    }
    else if (c > b && c > a) {
        a = c;
    }
    cout << a << endl << b << endl << c;
    return 0;
}