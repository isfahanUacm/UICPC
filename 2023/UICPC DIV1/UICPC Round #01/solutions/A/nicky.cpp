#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int R, C;
    cin >> R >> C;
    int maxr = -1, maxc = -1;
    for (int i = 0; i < R; i++) {
        int d;
        cin >> d;
        maxr = max(maxr, d);
    }
    for (int i = 0; i < C; i++) {
        int d;
        cin >> d;
        maxc = max(maxc, d);
    }

    if (maxr == maxc) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}
