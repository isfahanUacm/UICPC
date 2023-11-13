#include <iostream>

using namespace std;

int t[1111111][26];
int z[1111111][26];
int p[1111111][26];
int c;

int n, m;
string s;

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int k = 0;
        for (int j = 0; j < s.size(); j++) {
            char u = s[j]-'a';
            if (t[k][u] == 0) {
                t[k][u] = ++c;
                z[k][u] = i;
                p[k][u] = s.size();
            }
            k = t[k][u];
        }
    }
    for (int i = 1; i <= m; i++) {
        cin >> s;
        int k = 0;
        int r = 0, e = 0;
        int f = 0, g = 999999999;
        for (int j = 0; j < s.size(); j++) {
            char u = s[j]-'a';
            if (f != z[k][u]) {
                r += min(e+1,g-j+2);
                e = 0;
                f = z[k][u];
                g = p[k][u];
            } else {
                e++;
            }
            k = t[k][u];
            if (k == 0) {
                r += s.size()-j-1;
                break;
            }
        }
        int j = s.size();
        if (e != 0) {
            r += min(e,g-j+1);
            e = 0;
        }
        cout << r << "\n";
    }
}
