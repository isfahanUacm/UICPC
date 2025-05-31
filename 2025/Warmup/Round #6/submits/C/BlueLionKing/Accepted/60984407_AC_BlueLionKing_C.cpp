#include <iostream>
#include <cmath>
using namespace std;

int main() {
    long long int n;
    cin >> n;
    for (long long int i = 0; i < n; i++) {
        long long int o, p;
        cin >> o >> p;

        long long int first = ceil(sqrt(o));
        long long int last = floor(sqrt(p));

        if (first > last) {
            cout << 0 << endl;
        } else {
            cout << (last - first + 1) << endl;
        }
    }
}
