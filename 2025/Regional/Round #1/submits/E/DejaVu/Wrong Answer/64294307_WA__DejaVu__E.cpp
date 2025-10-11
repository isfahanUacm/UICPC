#include <iostream>
using namespace std;

int main() {
    freopen("ghanophobia.in", "r", stdin);
    
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int a, b;
        char colon;
        cin >> a >> colon >> b;

        if (2 + a == b * 2 + 6) {
            cout << "Case " << i + 1 << ": PENALTIES" << endl;
        } else if (2 + a > b * 2 + 6) {
            cout << "Case " << i + 1 << ": YES" << endl;
        } else {
            cout << "Case " << i + 1 << ": NO" << endl;
        }
    }
    return 0;
}
