#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {


    ll n;
    cin >> n;

    ll l, r;
    cin >> l >> r;

    ll a[n], b[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
        if (a[i] < l) a[i] = l;
        if (b[i] > r) b[i] = r;
        b[i]--;
    }

    sort(a, a + n);
    sort(b, b + n);

    int result[n];
    for (int i = 0; i < n; i++)
        result[i] = 0;

    for (int i = l; i < r; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            if (a[j] <= i and b[j] >= i) {
                ans++;
            }
        }
        result[ans]++;
    }

    for (int i = 1; i < n; i++) {
        result[i] += result[i - 1];
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }


    return 0;
}
