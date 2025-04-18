#include <algorithm>
#include <iostream>
#include <math.h>
#include <bits/ranges_algo.h>

using namespace std;

typedef long long ll;

int main() {


    int n, M, k;
    cin >> n >> M >> k;

    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + n);

    int ans = 0;


    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (j - i + 1 > k) {
                i = j - 1;
                ans++;
                break;
            }
            if (arr[j] - arr[i] > M) {
                i = j - 1;
                ans++;
                break;
            }
            if (j == n - 1) {
                ans++;
                i = j;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
