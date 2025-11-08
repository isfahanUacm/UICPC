#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    int arr[100];
    for (int i = 0; i < 100; ++i) {
        cin >> arr[i];
    }
    if (arr[99] % 10 == 0){
        cout << "10" << endl;
    } else {
        cout << arr[99] % 10 << endl;
    }
    return 0;
}