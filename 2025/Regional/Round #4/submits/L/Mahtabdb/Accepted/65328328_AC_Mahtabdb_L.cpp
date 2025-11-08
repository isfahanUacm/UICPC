#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; ++i) {
       cin >> arr[i];
    }
    int a = arr[0] / 3;
    int c = arr[n - 1] / 3;
    int b = arr[1] - (2 * a);
    cout << a << " " << b << " " << c << endl;
    return 0;
}