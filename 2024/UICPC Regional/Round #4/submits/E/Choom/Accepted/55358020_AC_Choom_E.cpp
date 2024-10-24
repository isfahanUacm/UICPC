#include <iostream>

using namespace std;

int main() {
    string s;
    cin >> s;

    string tmp;
    for (int i = 0; i < s.length(); i++)
        tmp += s[i] + 32;
    cout << tmp << endl;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'S' && s[i + 1] == 'S') {
            for (int j = 0; j < tmp.length(); j++) {
                if (j == i) {
                    cout << 'B';
                    j++;
                } else cout << tmp[j];
            }
            cout << endl;
        }
    }
    return 0;
}
