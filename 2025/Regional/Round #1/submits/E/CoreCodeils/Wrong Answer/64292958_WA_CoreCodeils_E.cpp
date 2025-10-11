#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

int main() {
    freopen("ghanophobia.in", "r", stdin);
    int t;
    cin >> t;

    for (int x = 1; x <= t; x++) {
        int m = 2;
        int g = 6;
        string s;
        cin >> s;
        m += s[0] - '0';
        g += (s[2] - '0') * 2;
        cout << "Case " << x << ": ";
        if (m > g)
            cout << "YES";
        else if (m < g)
            cout << "NO";
        else
            cout << "PENALTIES";
        cout << endl;
    }
    return 0;
}