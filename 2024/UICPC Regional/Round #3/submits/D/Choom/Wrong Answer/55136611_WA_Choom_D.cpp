#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    int a[1000000][2], line = 0;
    for (int i = 0; i < s.length() - 1; i++) {
        for (int j = 0; j < s.length() - 1 - i; j++) {
            if (s[j] > s[j + 1]) {
                swap(s[j], s[j + 1]);
                a[line][0] = j + 2;
                a[line][1] = j + 1;
                line++;
            }
        }
    }
    for (int i = line - 1; i >= 0; i--) {
        cout << a[i][0] << " " << a[i][1] << endl;
    }
    return 0;
}
