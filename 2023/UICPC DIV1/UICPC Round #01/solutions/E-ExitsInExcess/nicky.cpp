#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Who cares about r? ¯\_(ツ)_/¯
    int r, c;
    cin >> r >> c;
    vector<int> s;
    vector<int> l;

    for (int i = 0; i < c; i++) {
        int f, t;
        cin >> f >> t;
        auto smaller = f < t;
        if (smaller) {
            s.push_back(i + 1);
        } else {
            l.push_back(i + 1);
        }
    }

    auto smaller = s.size() < l.size() ? s : l;
    cout << smaller.size() << endl;
    for (auto i : smaller) {
        cout << i << endl;
    }

    return 0;
}
