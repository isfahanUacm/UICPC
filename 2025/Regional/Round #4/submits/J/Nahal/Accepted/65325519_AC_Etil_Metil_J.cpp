#include <bits/stdc++.h>

using namespace std;

int main() {
    int arr[100];
    int temp[10];
    for (int i = 0; i < 100; i++) {
        cin >> arr[i];
    }
    int result = arr[99] % 10;
    if (result == 0) {
        result = 10;
    }
    cout << result;

    return 0;
}
