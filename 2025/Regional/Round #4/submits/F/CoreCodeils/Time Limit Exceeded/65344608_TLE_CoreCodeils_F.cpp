#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <math.h>
#include <set>
#include <vector>
#include <bits/ranges_algo.h>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n, k;
    cin >> n >> k;

    int x[n];
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    sort(x, x+n);

    long double mn =  1e12;

    for (int l = 0; l <= n - k; l++) {
        long double sum = 0;
        for (int i = l; i <  l + k; i++) {
            sum += x[i];
        }
        sum /= k;
        long double result = 0;
        for (int i = l; i < l + k; i++) {
            result += pow(x[i] - sum, 2);
        }
        mn = min(result, mn);
    }

    cout << fixed << setprecision(6) <<mn << endl;


    return 0;
}
