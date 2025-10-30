#include <iostream>
#include <string>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;

    int n = (s1.length() + s2.length() + s3.length()) / 2;

    int i1 = 0, i2 = 0, i3 = 0;
    string result = "";

    for (int k = 0; k < n; k++) {
        if (i1 < s1.length() && i2 < s2.length() && s1[i1] == s2[i2]) {
            result += '3';
            i1++;
            i2++;
        } else if (i1 < s1.length() && i3 < s3.length() && s1[i1] == s3[i3]) {
            result += '2';
            i1++;
            i3++;
        } else if (i2 < s2.length() && i3 < s3.length() && s2[i2] == s3[i3]) {
            result += '1';
            i2++;
            i3++;
        }
    }

    cout << result << endl;
    return 0;
}