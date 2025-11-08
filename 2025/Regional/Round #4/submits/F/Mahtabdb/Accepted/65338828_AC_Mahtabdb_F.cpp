#include <bits/stdc++.h>
using namespace std;

int main() {


    int n, k;
    cin >> n >> k;
    vector<long long> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    sort(arr.begin(), arr.end());

    long long sum = 0, sumSq = 0;
    for (int i = 0; i < k; ++i) {
        sum += arr[i];
        sumSq += arr[i] * arr[i];
    }

    long double minBadness = (long double)sumSq - (long double)sum*sum/k;

    for (int i = 1; i <= n - k; ++i) {
        sum = sum - arr[i-1] + arr[i+k-1];
        sumSq = sumSq - arr[i-1]*arr[i-1] + arr[i+k-1]*arr[i+k-1];
        long double badness = (long double)sumSq - (long double)sum*sum/k;
        if (badness < minBadness) minBadness = badness;
    }

    cout << fixed << setprecision(6) << minBadness << "\n";
    return 0;
}
