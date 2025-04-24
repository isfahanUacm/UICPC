#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys;
    cin >> xt >> yt;
    cin >> xp >> yp;

    const long long BORDER = 1000000000LL;

    if ((xs < xp && xt > xp) || (xs > xp && xt < xp)) {
        long long x_mid = xs < xt ? xp - 1 : xp + 1;
        long long y_mid = ys < yp ? BORDER : -BORDER;

        cout << 4 << '\n';
        cout << xs << " " << y_mid << '\n';
        cout << x_mid << " " << y_mid << '\n';
        cout << x_mid << " " << yt << '\n';
        cout << xt << " " << yt << '\n';
    } else {
        long long y_detour = (abs(ys - BORDER) + abs(yt - BORDER) < abs(ys + BORDER) + abs(yt + BORDER)) ? BORDER : -BORDER;
        cout << 2 << '\n';
        cout << xs << " " << y_detour << '\n';
        cout << xt << " " << y_detour << '\n';
    }

    return 0;
}
