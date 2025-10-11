#include <iostream>

using namespace std;

int main() {
  freopen("ghanophobia.in", "r",stdin);
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        int a;
        cin >> a;
        char c;
        cin >> c;
        int b;
        cin >> b;


        int egept = 1;
        int gana = 6;
        egept += a;
        gana += b;
        if (egept > gana) {
            cout << "Case " << i << ":" << " YES" << endl;
        } else if (egept < gana) {
            cout << "Case " << i << ":" << " NO" << endl;
        } else {
            int newGana = 12 + b;
            int newEgept = 1 + 2 * a;
            if (newGana > newEgept) {
                cout << "NO" << endl;
            } else if (newGana < newEgept) {
                cout << "Case " << i << ":" << " YES" << endl;
            } else {
                cout << "Case " << i << ":" << " PENALTIES" << endl;
            }
        }
    }

    return 0;
}
