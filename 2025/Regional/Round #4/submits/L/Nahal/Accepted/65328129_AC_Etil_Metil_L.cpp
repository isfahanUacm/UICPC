#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int max = arr[n - 1] / 3;
    int min = arr[0] / 3;
    int mid = arr[n - 2] - 2 * max;
    cout << min << " " << mid << " " << max;

    return 0;
}
