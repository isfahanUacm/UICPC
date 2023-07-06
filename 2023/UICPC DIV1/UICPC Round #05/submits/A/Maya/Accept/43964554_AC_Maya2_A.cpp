#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);
    
    string str;
    cin >> str;

    bool hiss = false;
    for (int i = 1; i < str.size() ; ++i) {
        if (str[i-1] == 's' && str[i] == 's')
            hiss = true;
    }

    if (hiss) cout << "hiss";
    else cout << "no hiss";

    return 0;
}