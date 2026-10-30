#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vll vector<long long>

void solve() {

    int n;
    cin >> n;

    long int u = 0, d = 0, m = 0;
    long int ans = 0;

    int x,y;
    for (int i =0; i <n;i++) {
        cin >> x >> y;
        if (y > x) {
            u++;
        }
        else if (y < x) {
            d ++;
        }
        else
            if (y == x) {
                m++;
            }
    }

    ans += u * d;

    ans += u * m;
    ans += d * m;
    ans += m * (m - 1);

    cout << ans;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << endl;
    }

    return 0;
}