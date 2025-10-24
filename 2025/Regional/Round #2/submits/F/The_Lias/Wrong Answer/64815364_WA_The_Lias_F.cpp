#include <bits/stdc++.h>

using namespace std;

bool check (float arr[], int n, int t, int d) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ceil(arr[i]/d);
    }
    if (sum < t) return true;
    return false;
}

int main() {
    int n, t, sum = 0;
    cin >> n >> t;
    float arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    int d = sum / t;

    while (!check(arr, n, t, d)) {
        d++;
    }
    cout << d;
    return 0;
}