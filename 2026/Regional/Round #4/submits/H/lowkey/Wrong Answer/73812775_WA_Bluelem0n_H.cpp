
#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        long long first;
        cin >> first;

        bool same = true;
        bool allOne = (first == 1);

        for (int i = 1; i < n; i++) {
            long long x;
            cin >> x;

            if (x != first) {
                same = false;
            }

            if (x != 1) {
                allOne = false;
            }
        }

        if (allOne) {
            cout << 0 << '\n';
        }
        else if (same) {
            cout << 1 << '\n';
        }
        else {
            cout << 2 << '\n';
        }
    }

    return 0;
}
