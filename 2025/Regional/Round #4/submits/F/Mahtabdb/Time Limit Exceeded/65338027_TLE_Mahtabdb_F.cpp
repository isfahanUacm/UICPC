#include <iostream>
#include "algorithm"
#include "cmath"
#include <iomanip>

using namespace std;

int main() {
    int n , k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr , arr + n);
    double min_fin = 1e18;
    for (int i = 0; i <= n - k; ++i) {
        double ave = 0;
        for (int j = 0; j < k; ++j) ave += arr[i + j];
        ave /= k;
        double fin = 0;
        for (int j = 0; j < k; ++j) fin += pow(arr[i+j]-ave, 2);
        min_fin = min(min_fin, fin);
    }
    cout << fixed << setprecision(6) << min_fin << endl;
    return 0;
}