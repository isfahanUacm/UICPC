#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int t;
    cin >> t;

    long double n[t], sum = 0;
    for (int i = 0; i < t; i++) {
        cin >> n[i];
        if (n[i] == 0) sum += 2;
        else sum = sum + (1.0 / n[i]);
    }

    cout << fixed << showpoint << setprecision(8) << sum;

    return 0;
}
