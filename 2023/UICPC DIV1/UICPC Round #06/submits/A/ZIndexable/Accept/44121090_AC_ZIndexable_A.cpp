#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n;
    cin >> n;
    float sum = 0;
    for (int i = 0; i < n; ++i) {
        float a, b;
        cin >> a >> b;
        sum += (a * b);
    }
    cout << fixed << setprecision(3) << sum;
    return 0;
}
