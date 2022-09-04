#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int sym(string s) {

    int i, j;
    if (s.size() % 2 == 0) {
        i = s.size() / 2 - 1;
        j = s.size() / 2;
    } else {
        return 0;
    }

    int c = 0;
    while (i >= 0 && j < s.size()) {
        if (s[i] == s[j])
            c++;
        i--;
        j++;
    }
    return c;
}


int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string same, diff1, diff2;

    for (int i = 0; i < s1.size(); ++i) {

        if (s1[i] == s2[i])
            same.append(1, s1[i]);
        else {
            diff1.append(1, s1[i]);
            diff2.append(1, s2[i]);
        }
    }

    std::reverse(diff1.begin(), diff1.end());

    if (diff1 == diff2) {
        cout << 1 + sym(same);
    } else {
        cout << 0;
        return 0;
    }

    return 0;
}