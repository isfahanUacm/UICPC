#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string a;
    cin >> a;
    ll ans = 0;
    ll o = 0, t = 0;
    for (auto x : a) {
        if (x == '0') {
            ans += o;
            ans += t;
        }
        else if (x == '1') {
            ans += t;
            o++;
        }
        else {
            t++;
        }
    }
    cout << ans << endl;
}
