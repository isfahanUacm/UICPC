#include <bits/stdc++.h>
#include <chrono>
using namespace std;


int main() {
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int count = 1;
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != arr[i + 1]) {
            count++;
        }
    }
    if (count >= k) {
        cout << k;
    } else {
        cout << count;
    }

    return 0;
}
