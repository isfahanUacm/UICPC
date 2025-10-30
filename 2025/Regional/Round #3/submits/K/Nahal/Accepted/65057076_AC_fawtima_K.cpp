#include <bits/stdc++.h>
using namespace std;


int main() {
    long long int c, n;
    cin >> c >> n;
    if (n > c) {
        cout << c + 1 << endl;
    } else if (n < c) {
        cout << 0 << endl;
    } else {
        cout << n << endl;
    }


    return 0;
}
