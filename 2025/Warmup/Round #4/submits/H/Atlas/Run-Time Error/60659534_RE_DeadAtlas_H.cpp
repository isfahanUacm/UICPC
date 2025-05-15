#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {

    ll v ;
    cin >> v ;
    ll s, f;
    cin >> s >> f;

    ll arr[f - s];
    for (ll i = 0; i < f - s; i++)
        arr[i] = 0;

    for (ll i = 0; i < v; i++) {
        int a, b;
        cin >> a >> b;
        if (a < s) a = s;
        if (b > f) b = f;
        b = b - s - 1;
        a -= s;
        for (ll j = a; j <= b; j++)
            arr[j]++;
    }


    // for (int i = 0; i < f - s; i++) {
    //     cout << arr[i] << " ";
    // }

    int ans[v];
    for (ll i = 0; i < v; i++)
        ans[i] = 0;
    for (int i = 0; i < v; i++) {
        for (int j = 0; j < f - s; j++) {
            if (arr[j] == i)
                ans[i]++;
        }
        if (i > 0)
            ans[i] += ans[i - 1];
        if (ans[i] > f - s) ans[i] = f - s;
    }

    for (int i = 0; i < v; i++)
        cout << ans[i] << " ";

    return 0;
}
