#include <bits/stdc++.h>
using namespace std;

int main()
{
    double a;
    cin >> a;

    double op1 = 100 / a;
    double op2 = 100 / (100 - a);

    cout << setprecision(4) << fixed << (op1) << '\n';
    cout << setprecision(4) << fixed << (op2);

    return 0;
}