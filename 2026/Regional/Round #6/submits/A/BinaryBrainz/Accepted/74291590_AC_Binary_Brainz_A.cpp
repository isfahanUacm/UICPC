#include <bits/stdc++.h>
using namespace std;

void solve() {

    string s;
    cin >> s;

    if (s.length() & 1) {
        cout << s[s.length()/2];
    }
    else {
        cout <<":)" ;
    }

}


int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    solve();

    return 0;
}