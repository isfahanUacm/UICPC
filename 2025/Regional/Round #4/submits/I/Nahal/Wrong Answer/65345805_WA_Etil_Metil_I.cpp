#include <bits/stdc++.h>
#include <chrono>
using namespace std;


int main() {
    long int n;
    long double arr[n];
    long double temp[n];

    long double sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        sum += temp[i];
    }
    sum += arr[n - 1];
    sum /= double(n);
    cout << fixed << setprecision(6) << sum << endl;


    return 0;
}
