# include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int p1 = 0, p2 = 0, p3 = 0;
    string res;

    while (p1 < s1.size() || p2 < s2.size() || p3 < s3.size()) {
        char c1 = (p1 < s1.size()) ? s1[p1] : 0;
        char c2 = (p2 < s2.size()) ? s2[p2] : 0;
        char c3 = (p3 < s3.size()) ? s3[p3] : 0;

        if (c1 && c1 == c2) {
            res += c1;
            p1++; p2++;
        }
        else if (c1 && c1 == c3) {
            res += c1;
            p1++; p3++;
        }
        else if (c2 && c2 == c3) {
            res += c2;
            p2++; p3++;
        }
        else {
         
            if (c1) { res += c1; p1++; }
            else if (c2) { res += c2; p2++; }
            else if (c3) { res += c3; p3++; }
        }
    }

    cout << res << endl;
    return 0;
}

