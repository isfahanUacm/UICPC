#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, p, x;
    cin >> n >> p;
    char c;
    int s[p], t[p], f[p];
    for(int i = 0; i < p; i++) {
        s[i] = 0;
        t[i] = 0;
        f[i] = 0;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < p; j++) {
            cin >> c >> x;
            if (c == '+') {
                s[j] ++;
            }
            if (c == '+' || x > 0) {
                t[j] ++;
            }
            f[j] += x;
        }
    }
    for(int i = 0; i < p; i++) {
        cout << s[i] << ' ' << t[i] << ' ' << f[i] << endl;
    }
    return 0;
}
