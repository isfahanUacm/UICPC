/*
 * https://open.kattis.com/problems/deceptivedice
 * Author: https://github.com/smh997 
 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    double l, e = 0;
    cin >> n >> k;
    for (int i = 0; i < k; ++i) {
        l = (int)e;
        e = (l * e + (n * (n + 1) - l * (l + 1)) / 2) / n;
    }
    cout << fixed << setprecision(8) << e << endl;
    return 0;
}

