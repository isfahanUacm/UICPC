#include <iostream>

using namespace std;

int main() {
    int x, y, n;
    cin >> x >> y >> n;

    for (int i = 1; i <= n; ++i) {
        int div = 0;
        if (i%x == 0) {
            ++div;
            cout << "Fizz";
        }
        if (i%y == 0) {
            ++div;
            cout << "Buzz";
        }
        if (div == 0) cout << i;
        cout << endl;
    }
    return 0;
}
