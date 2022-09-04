#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2;
    cin >> s1>> s2;
    if (s1 == s2){
        cout << 0;
        return 0;
    }

    int fd;
    int ld;

    for (int i = 0; i < s1.size(); ++i) {
        if (s1[i] != s2[i]){
            fd = i;
            break;
        }
    }

    for (int i = s1.size() - 1; i >= 0; --i) {
        if (s1[i] != s2[i]){
            ld = i;
            break;
        }
    }

    int len = ld - fd;

    bool suc = true;

    for (int i = 0; i <= len; ++i) {
        if (s1[fd + i] != s2[ld - i]){
            suc = false;
            break;
        }
    }

    if(!suc){
        cout << 0;
        return 0;
    }
    int before= fd - 1;
    int after = ld + 1;

    long ans = 1;
    while (after < s1.size() && before >= 0){
        if (s1[before] == s1[after]){
            ans++;
        }
        before--;
        after++;
    }

    cout << ans;
    return 0;
}
