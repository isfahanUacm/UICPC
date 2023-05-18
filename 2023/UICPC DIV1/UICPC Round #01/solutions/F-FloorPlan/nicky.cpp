#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int m, k;
    if (n % 4 == 0) {
        m = (n + 4) / 4;
        k = m - 2;
        cout << m << " " << k << endl;
    } else if (n % 2 == 1) {
        m = (n + 1) / 2;
        k = m - 1;
        cout << m << " " << k << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
