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
    double ave = 0;
    for (int i = 0; i < k; ++i) {
        ave += arr[i];
    }
    ave /= k;
    double fin = 0;
    for (int i = 0; i < k; ++i) {
        fin += pow(abs(ave - arr[i]) , 2);
    }
    cout << fixed << setprecision(6) << fin << endl;
    return 0;
}