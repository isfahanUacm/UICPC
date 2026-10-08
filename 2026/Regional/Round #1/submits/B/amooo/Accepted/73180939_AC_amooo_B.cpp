#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s, t;
    cin >> s >> t;
    string p = s;

    for (int i = 0; i < n / 2; i++) {
        int j = n - 1 - i;
        int a[4];
        a[0] = s[i] - 'a';
        a[1] = s[j] - 'a';
        a[2] = t[i] - 'a';
        a[3] = t[j] - 'a';
        for (int x = 0; x < 4; x++) {
            for (int y = x + 1; y < 4; y++) {
                if (a[x] > a[y]) {
                    int temp = a[x];
                    a[x] = a[y];
                    a[y] = temp;
                }
            }
        }
        char c = 'a' + a[1];
        p[i] = c;
        p[j] = c;
    }
    if (n % 2 == 1) {
        int mid = n / 2;
        int x = s[mid] - 'a';
        int y = t[mid] - 'a';
       if (x > y) {
            int temp1 = x;
            x = y;
            y = temp1;
        }
        p[mid] = 'a' + x;
    }
    cout << p << endl;
    return 0;
    }