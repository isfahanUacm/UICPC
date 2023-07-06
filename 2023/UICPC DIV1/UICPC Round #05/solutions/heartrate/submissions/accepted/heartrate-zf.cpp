#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    cout.setf(ios::fixed);
    cout.precision(10);

    int n;
    cin >> n;
    while (n--) {
        double b, p;
        cin >> b >> p;

        cout << (b-1)*60/p << ' ' << b*60/p << ' ' << (b+1)*60/p << endl;
    }

    return 0;
}
