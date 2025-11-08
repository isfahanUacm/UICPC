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

    int rg,gb;
    cin >> rg >> gb;

    if (r > rg || b > gb || g > rg + gb)
        cout << -1;
    else {
        cout << r + g + max(b - r - g,0);
    }


    return 0;
}
