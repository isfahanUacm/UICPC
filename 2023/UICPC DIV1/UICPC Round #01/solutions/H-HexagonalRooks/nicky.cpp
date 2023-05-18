#include <iostream>
#include <string>
#include <set>
#include <utility>

using namespace std;

bool outside(int x, int y) {
    int d = abs(5 - x);
    return y < d || y >= 22 - d;
}

bool onSameLine(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) {
        return true;
    }
    if (a.first + a.second == b.first + b.second) {
        return true;
    }
    if (a.first - a.second == b.first - b.second) {
        return true;
    }

    return false;
}

int main() {
    string a, b;
    cin >> a >> b;

    int xa, xb, ya, yb;
    int tya, tyb;
    tya = stoi(a.substr(1));
    tyb = stoi(b.substr(1));

    // Convert to useful grid...
    xa = a[0] - 'a';
    xb = b[0] - 'a';

    int da = abs(a[0] - 'f');
    int db = abs(b[0] - 'f');

    ya = (tya - 1) * 2 + da;
    yb = (tyb - 1) * 2 + db;

    // cout << "(" << xa << ", " << ya << ") - (" << xb << ", " << yb << ")" << endl;

    set<pair<int, int> > possible;

    for (int y = 0; y < 22; y++) {
        for (int x = 0; x < 11; x++) {
            if (x % 2 == y % 2) {
                continue;
            } else {
                // Ignore points outside of the grid
                if (outside(x, y)) {
                    continue;
                }
                // If it is the same as either (xa, ya) or (xb, yb), ignore it
                if (x == xa && y == ya) {
                    continue;
                }
                if (x == xb && y == yb) {
                    continue;
                }

                // Check if it is on the same line as both (xa, ya) and (xb, yb). If so, it is valid
                if (onSameLine(make_pair(x, y), make_pair(xa, ya)) && onSameLine(make_pair(x, y), make_pair(xb, yb))) {
                    possible.insert(make_pair(x, y));
                }
            }
        }
    }

    // for (int y = 0; y < 22; y++) {
    //     for (int x = 0; x < 11; x++) {
    //         if (x % 2 == y % 2) {
    //             cout << " ";
    //         } else {
    //             // Check if outside of grid
    //             if (outside(x, y)) {
    //                 cout << " ";
    //             } else if (x == xa && y == ya) {
    //                 cout << "a";
    //             } else if (x == xb && y == yb) {
    //                 cout << "b";
    //             } else if (possible.find(make_pair(x, y)) != possible.end()) {
    //                 cout << "x";
    //             } else {
    //                 cout << ".";
    //             }
    //         }
    //         cout << "  ";
    //     }
    //     cout << endl;
    // }

    cout << possible.size() << endl;

    return 0;
}
