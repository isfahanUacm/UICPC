#include <bits/stdc++.h>
using namespace std;

int main() {
    int a;
    cin >>a;
    int ans=0;
    for (int i = 0; i < a; ++i) {
        string tmp;
        cin >> tmp;
        bool won = true;
        for (int j = 0; j < tmp.length() - 1; ++j) {
            if (tmp[j] == 'D' &&  tmp[j + 1] == 'C') {
                won = false;
            }
        }

        if (won)
            ans++;
    }
    cout <<ans;
    return 0;
}
