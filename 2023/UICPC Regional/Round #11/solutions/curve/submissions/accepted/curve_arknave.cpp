#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

int main() {
    double R, S;
    while (cin >> R >> S) {
        double V = sqrt(R * (S + .16) / 0.067);

        cout << static_cast<int64_t>(V + 0.5) << '\n';
    }
    return 0;
}
