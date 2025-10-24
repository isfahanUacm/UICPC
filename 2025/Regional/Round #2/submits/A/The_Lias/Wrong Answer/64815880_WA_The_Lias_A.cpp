#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, s;
    char direction;
    cin >> n;
    cin >> s;
    cin >> direction;
    int a = 0, b = 0, c = 0;
    if (direction == 'L' && s != n && s != 1) {
        c = n - s;
        a = s / 2;
        b = a;
        if (s % 2 == 1) {
            a++;
            b++;
        }
    }
    else if ((direction == 'L' && s == n) || (direction == 'R' && s == 1)) {
        a = n/ 2;
        if (n % 2 == 1) {
            a++;
        }
        b = a;
        c = a;
    }
    else if ((direction == 'L' && s == 1) || (direction == 'R' && s == n)) {
        b = 1;
        a = n / 2;
        if (n % 2 == 1) {
            a++;
        }
        c = a;
    }
    else {
        a = s - 1;
        b = (n-s)/2;
        c = b;
        if ((n-s) % 2 == 1) {
            b++;
            c++;
        }
    }
    cout << a << ' ' << b << ' ' << c;
    return 0;
}