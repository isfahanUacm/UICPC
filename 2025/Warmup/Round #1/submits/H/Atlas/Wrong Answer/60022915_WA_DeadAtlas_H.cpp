#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {


    // int n, m;
    // cin >> n >> m;
    //
    // int arr[n];
    // for (int i = 0; i < n; i++) {
    //     cin >> arr[i];
    // }
    //
    // int arrDif[n-1];
    // for (int i = 0; i < n-1; i++) {
    //     arrDif[i] = abs(arr[i+1] - arr[i]);
    // }
    //
    // sort (arrDif, arrDif+n-1);
    //
    // for (int i = 0; i < n - 1; i++) {
    //     cout << arrDif[i] << " ";
    // }
    //
    // int ans = -1;
    // for (int i = 0; i <= arrDif[n - 1]; i++) {
    //     int count = 0;
    //     for (int j = 0; j < n - 1; j++) {
    //         if (arrDif[j] > i) {
    //             count++;
    //         }
    //         if (count == m) break;
    //     }
    //     if (count + 1 == m) {
    //         ans = i;
    //         break;
    //     }
    // }
    //
    // cout << endl << ans << endl;



    int n;
    cin >> n;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int ans[n];
    for (int i = 0; i < n; i++) {
        ans[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        int x = i;
        while (arr[x] != 0) {
            x = arr[x] - 1;
            if (arr[x] == 0)
                ans[x] += 1;
        }
    }


    int maxAns = 0;
    int maxIndex = 0;
    for (int i = 0; i < n; i++) {
        if (ans[i] > maxAns) {
            maxAns = ans[i];
            maxIndex = i + 1;
        }
    }

    cout << maxIndex << " " << maxAns + 1 << endl;

    return 0;
}
