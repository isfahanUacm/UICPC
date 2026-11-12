#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    double n;
    cin >> n;

    vector<double> d(n);
    vector<double> p(n);
    for(int i =0 ; i < n; i++)
    {
        cin >> d[i];
    }

    for(int i =0 ; i < n; i++)
    {
        cin >> p[i];
    }

    cout << fixed << setprecision(9);

    long double bst = 0 + ((1.0 / p[0]) - 1.0) * n + d[0];

    for (int i = 1; i < n; i++) {
        long double x = i + ((1.0 / p[i]) - 1.0) * n + d[i];

        bst = min(bst, x);
    }

    cout << bst;

    return 0;
}