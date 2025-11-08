#include <iostream>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int r,g,b;
    cin >> r >> g >> b;

    int r2,g2,b2;
    cin >> r2 >> g2 >> b2;

    r -= r2;
    g -= g2;
    b -= b2;

    r = max(r,0);
    g = max(g,0);
    b = max(b,0);

    int rg,gb;
    cin >> rg >> gb;

    int res = 0;
    if (r > rg) {
        cout << -1;
        return 0;
    }
    res += r;
    rg -= r;

    if (b > gb) {
        cout << -1;
        return 0;
    }
    res += b;
    gb -= b;

    if (g > gb + rg) {
        cout << -1;
        return 0;
    }
    res += g;

    cout << res;

    return 0;
}
