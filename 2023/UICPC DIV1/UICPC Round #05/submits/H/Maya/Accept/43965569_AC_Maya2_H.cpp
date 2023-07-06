#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pii pair<int, int>
#define F first
#define S second
#define vi vector<int>
#define pb push_back
#define pf push_front

void solve() 
{
    ld b, p, x2, x;
    cin >> b >> p;
    x2 = b * 60.0 / p;
    x = 60.0 / p;
    cout << fixed << setprecision(4);
    cout << x2 - x << ' ' << x2 << ' ' << x2 + x << '\n'; 
}

int main()
{
    int t;
    cin >> t;
    while (t--) solve();

    return 0;
}