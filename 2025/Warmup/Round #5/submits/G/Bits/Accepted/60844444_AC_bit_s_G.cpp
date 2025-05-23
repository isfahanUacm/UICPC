#include <bits/stdc++.h>
using namespace std;

#define ll long long
ll const INF = 1e16;

void solve() {
    int n;
    cin >> n;
    if(n>1 && n < 13)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
        solve();

    return 0;
}
