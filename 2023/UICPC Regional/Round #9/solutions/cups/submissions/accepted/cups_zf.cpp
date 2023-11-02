#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main() {
    string cups[1000];
    int n;
    cin >> n;

    while (n--) {
        cin >> ws;
        string cup;
        int rad;
        if (isdigit(cin.peek())) {
            cin >> rad >> cup;
            cups[rad/2] = cup;
        }
        else {
            cin >> cup >> rad;
            cups[rad] = cup;
        }
    }

    for (auto s : cups)
        if (s != "")
            cout << s << endl;
    return 0;
}
