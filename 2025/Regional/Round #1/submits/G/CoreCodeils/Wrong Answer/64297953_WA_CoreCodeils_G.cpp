#include <iostream>
#include <fstream>
using namespace std;

int main() {
    freopen("jenga.in", "r", stdin);
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        int n;
        int n1 = 0, n2 = 0;
        cin >> n;
        int x = n;
        while (x >= 3) {
            n1 += x / 3;
            x /= 3;
        }
        // x = n;
        // int temp = 0;
        // while (x >= 2) {
        //     n2 += x * 2 / 3;
        //     temp += x * 2 % 3;
        //     x = x * 2 / 3;
        //     if (temp >= 3) {
        //         temp -= 3;
        //         x++;
        //     }
        // }

        cout << "Case " << i << ": ";
        if ((n + n1) % 2 == 0)
            cout << "Bakkar" << (i == t ? "" : "\n");
        else
            cout << "Wahdan" << (i == t ? "" : "\n");
    }
    return 0;
}
