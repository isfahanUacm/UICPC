#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    int arr[100];
    for (int i = 0; i < 100; ++i) {
        cin >> arr[i];
    }
    cout << arr[99]%10 << endl;
    return 0;
}
