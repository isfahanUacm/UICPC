#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    long double arr[n];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long double sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    long double avg = sum / double(n);
    long double temp[n];
    for (int i = 0; i < n; i++) {
        temp[i] = abs(arr[i] - avg);
    }
    long double max = -1;
    int i_max = 0;
    int count = n - k;
    while (count > 0) {
        for (int i = 0; i < n; i++) {
            if (temp[i] > max) {
                max = temp[i];
                i_max = i;
            }
        }
        temp[i_max] = 0;
        arr[i_max] = 0;
        max = -1;
        i_max = 0;
        count--;
    }
    long double sum2 = 0;
    for (int i = 0; i < n; i++) {
        sum2 += arr[i];
    }
    long double ave2 = sum2 / double(k);
    long double result = 0.0;
    for (int i = 0; i < n; i++) {
        if (arr[i] != 0) {
            result += pow(arr[i] - ave2, 2);
        }
    }
    cout << defaultfloat << setprecision(6) << result;
    return 0;
}

