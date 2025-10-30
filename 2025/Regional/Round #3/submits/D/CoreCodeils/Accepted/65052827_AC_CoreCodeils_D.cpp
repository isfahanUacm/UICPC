#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a[30] = {};
    string s;
    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        a[s[i] - 'a']++;
    }

    int check = 0;
    if (s.length() % 2 == 1)
        check = 1;

    for (int i = 0; i < 30; i++) {
        if (a[i] % 2 == 1)
            check--;
        if (check < 0) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;

    return 0;
}