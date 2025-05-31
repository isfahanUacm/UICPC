#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        int y = 0;
        for (int j = 2; j <= t; ++j) {
            int ch = 0;
            for (int k = 2; k < j; ++k) {
                if (j % k == 0) {
                    ch++;
                    break;
                }
            }
            if (ch == 0 && (j * 2) > t) {
                y++;
            }
        }
        cout << y << endl;
    }
}
