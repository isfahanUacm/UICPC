#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    double n[t], sum = 0;
    for (int i = 0; i < t; i++) {
        cin >> n[i];
        if (n[i] == 0) sum += 2;
        else sum = sum + (1 / n[i]);
    }

    cout << sum;

    return 0;
}
