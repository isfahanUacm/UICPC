#include <iostream>
using namespace std;

int main() {

    int t;
    cin >> t;
    while (t--)
    {
        int n;
    cin >> n;
    int arr[100005];
    int i = 0;
    for (int j = 2; j<n; j+=2) {
        arr[i++] = j;
    }

    if (n % 2 == 0) {
        arr[i++] = n;
    }

    for (int j = 1; j < n; j += 2) {
        arr[i++] = j;
    }

    if (n % 2 == 1) {
        arr[i++] = n;
    }

    for (int i = 0; i<n; i++) {
        cout << arr[i] << " ";
    }
    }
    

    return 0;
}