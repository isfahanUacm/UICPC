#include <bits/stdc++.h>
using namespace std;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    long long ans = 0;
    if (n % 2 == 0) {
        for (int i = 0; i <= n; i+=2) {
            ans += i;
        }
    }
    else {
        for (int i = 1; i <= n; i+=2) {
            ans += i;
        }
    }
    cout << ans;
    return 0;
}