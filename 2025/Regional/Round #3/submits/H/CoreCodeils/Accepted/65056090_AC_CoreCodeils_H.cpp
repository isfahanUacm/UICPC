#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int i1 = 0,i2 = 0,i3 = 0;
    string s1,s2,s3;
    cin >> s1 >> s2 >> s3;
    string res = "";

    while (i1 < s1.size() || i2 < s2.size() || i3 < s3.size()) {
        int a[4] = {};
        if (i1 < s1.size())
            a[s1[i1] - '0']++;

        if (i2 < s2.size())
            a[s2[i2] - '0']++;

        if (i3 < s3.size())
            a[s3[i3] - '0']++;

        int mx = -1;
        int imx = 0;
        for (int i = 1; i <= 3; i++) {
            if (mx < a[i]) {
                mx = a[i];
                imx = i;
            }
        }

        if (i1 < s1.size())
            if (imx + '0' == s1[i1])
                i1++;


        if (i2 < s2.size())
            if (imx + '0' == s2[i2])
                i2++;

        if (i3 < s3.size())
            if (imx + '0' == s3[i3])
                i3++;

        res += imx + '0';

    }

    cout << res << endl;
    return 0;
}