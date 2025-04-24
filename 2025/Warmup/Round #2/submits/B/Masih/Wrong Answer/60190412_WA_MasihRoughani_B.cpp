#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    long long xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys;
    cin >> xt >> yt;
    cin >> xp >> yp;

    const long long YUP = 1000000000LL;
    const long long YDOWN = -1000000000LL;

    long long costUp = llabs(ys - YUP) + llabs(yt - YUP);
    long long costDown = llabs(ys - YDOWN) + llabs(yt - YDOWN);

    long long Y = (costUp < costDown ? YUP : YDOWN);

    cout << 2 << '\n';
    cout << xs << " " << Y << '\n';
    cout << xt << " " << Y << '\n';
    return 0;
}