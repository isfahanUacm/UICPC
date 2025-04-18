#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {

    int n, k;
    cin >> n >> k;
    int arrk[k];
    int ans = n;

    for (int i = 0; i < k; i++) {
        cin >> arrk[i];
    }

    int tmpk = k;

    for (int i = 0; i < k; i++) {
        ans += arrk[i] * (pow(2, (tmpk - 1)));
        tmpk--;
    }

    cout << ans << endl;

    // int n, M, k;
    // cin >> n >> M >> k;
    //
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    //
    // sort(arr, arr + n);
    //
    // int ans = 1;
    //
    //
    // for (int i = 0; i < n; i++) {
    //     ans++;
    //     for (int j = i + 1; j < n; j++) {
    //         if (j - i > k) {
    //             i = j;
    //             break;
    //         }
    //         if (arr[j] - arr[i] > M) {
    //             i = j;
    //             break;
    //         }
    //     }
    // }
    //
    // cout << ans << endl;

    return 0;
}
