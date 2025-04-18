#include <iostream>
#include <math.h>

using namespace std;

typedef long long ll;

int main() {

    ll n;
    cin >> n;

    ll min = 0;
    ll ans = 0;

    ll arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    for (int i = 0; i < n; i++) {
        ans += arr[i];
        if (ans <= min)
            min = ans;
    }

    cout << abs(min) << endl;


    // int n, k;
    // cin >> n >> k;
    // int arrn[n];
    // int arrk[k];
    //
    // int ans = 0;
    //
    // for (int i = 0; i < n; i++) {
    //     arrn[i] = 0;
    // }
    //
    // for (int i = 0; i < k; i++) {
    //     cin >> arrk[i];
    // }
    //
    // for (int i = 0; i < k; i++) {
    //     arrn[arrk[i]] = 1;
    // }
    //
    // int x = 0;
    // while (x < n) {
    //     if (arrn[x] == 1) {
    //         arrn[x] = 0;
    //         x = 0;
    //     }
    //     else {
    //         x++;
    //     }
    //     ans++;
    // }
    //
    // cout << ans << endl;

    return 0;
}
