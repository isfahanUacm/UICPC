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
        int r = 0;
        int l = 0;

        int index = 0;
        for (int i = 0; i < s.length(); i++)
            if (s[i] == ':')
                index = i;

        for (int i = 0; i < index; i++)
            r = 10 * r + s[i] - '0';

        for (int i = index + 1; i < s.length(); i++)
            l = 10 * l + s[i] - '0';

        m += r;
        g += l * 2;
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
