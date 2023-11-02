#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

ull p, a, b, c, d, n;

double solve(ull k)
{
    double ans = p * (sin(a * k + b) + cos(c * k + d) + 2);
    return ans;
}

int main()
{
    cin >> p >> a >> b >> c >> d >> n;

    double prices[n];

    for (int i = 0; i < n; i++)
    {
        prices[i] = solve(i + 1);
    }

    double ld = 0;
    double m = prices[0];
    for (int i = 0; i < n; i++) {
        ld = max(ld, m - prices[i]);
        m = max(m, prices[i]);
    }

    cout << setprecision(6) << fixed << ld;

    return 0;
}