#include <iostream>
using namespace std;

int main() {
    int n, t, k, d;
    cin >> n >> t >> k >> d;

    int pp = (n + k - 1) / k;
    int y = pp * t;

    int tt = 0;
    int cc = 0;
    while (true) {
        tt += t;
        if (tt > d) cc += 2 * k;
        else cc += k;

        if (cc >= n) break;
    }

    if (tt < y)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
