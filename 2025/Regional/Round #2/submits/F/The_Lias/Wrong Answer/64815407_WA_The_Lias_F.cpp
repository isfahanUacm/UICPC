#include <bits/stdc++.h>

using namespace std;

bool check (float arr[], long long int n, long long int t, long long int d) {
    long long int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += ceil(arr[i]/d);
    }
    if (sum < t) return true;
    return false;
}

int main() {
    long long int n, t, sum = 0;
    cin >> n >> t;
    float arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
        sum += arr[i];
    }
    long long int d = sum / t;

    while (!check(arr, n, t, d)) {
        d++;
    }
    cout << d;
    return 0;
}