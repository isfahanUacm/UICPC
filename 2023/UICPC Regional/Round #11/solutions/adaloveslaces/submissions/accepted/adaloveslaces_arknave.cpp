#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

constexpr bool DEBUG = false;

int n, d, s, t, f_min, f_max;
vector<double> lengths;

// r - which row?
void recur(int r, int used, double len) {
    assert((used & (1 << r)) > 0);
    if (r == n - 1) {
        lengths.push_back(len);
    }

    for (int i = 1; i < n; ++i) {
        if (used & (1 << i)) {
            continue;
        }

        int dist = abs(r - i);
        // adjacent
        if (dist == 1) {
            recur(i, used | (1 << i), len + 2.0 * d + 2 * t);
        }

        // cross
        double diag = hypot(s, dist * d);
        recur(i, used | (1 << i), len + 2.0 * diag + 2 * t);
    }
}

int main() {
    cin >> n >> d >> s >> t >> f_min >> f_max;

    recur(0, 1, s + 2 * t);

    if (DEBUG) {
        cerr << "Total lengths: " << lengths.size() << '\n';
        for (auto& l : lengths) {
            cerr << "(" << l + 2 * f_min << " " << l + 2 * f_max << ")" << endl;
        }
        cerr << endl;
    }

    int l;
    while (cin >> l) {
        int ans = 0;
        for (double len : lengths) {
            if (len + 2 * f_min <= l && l <= len + 2 * f_max) {
                ++ans;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
