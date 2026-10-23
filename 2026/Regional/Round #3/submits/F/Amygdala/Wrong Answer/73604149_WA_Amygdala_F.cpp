#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define ld long double
#define int ll

int const N =  1e6+9;
int const INF = 1e9;
ll const mod = 1e9;

int a[N];

void solve() {
    string s;
    cin >> s;
    cout << (s.size()<2 ? 0 : s.size()) << '\n';
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
        solve();

    return 0;
}