// I'm seeing running times of 0.3s vs 16s for this algorithm vs the
// time limit exceeded Python implementation!

#include <iostream>
#include <vector>
#include <string>

using namespace std;

typedef unsigned int ui;
typedef vector<ui> vu;

vu fact(ui n) {
    vu pdiv;
    for (ui d = 2; d*d <= n; ++d) {
        if (n%d == 0) {
            ui x = 0;
            while (n%d == 0) {
                n /= d;
                ++x;
            }
            pdiv.push_back(x);
        }
    }
    if (n > 1) pdiv.push_back(1);
    return pdiv;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        ui n;
        string name;
        cin >> n >> name;
        vu pdiv = fact(n);

        int win;
        if (pdiv.size() == 1) win = 1-(pdiv[0]%2);
        else if (pdiv.size() >= 3) win = 2;
        else {
            if (pdiv[0] == pdiv[1]) win = 1;
            else if (pdiv[0]+1 == pdiv[1] || pdiv[0] == pdiv[1]+1) win = 0;
            else win = 2;
        }

        if (win == 2) cout << "tie" << endl;
        else if ((!win && name == "Alice") || (win && name == "Bob")) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }
    return 0;
}
