#include <bits/stdc++.h>
using namespace std;


int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    bool flag = false;
    int counter = 1;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == s[i + 1]) {
            counter++;
        } else {
            if (counter % 2 == 1) {
                if (flag == false) {
                    flag = true;
                } else {
                    cout << "no" << endl;
                    return 0;
                }
            }
            counter = 1;
        }
    }
    cout << "yes" << endl;


    return 0;
}
