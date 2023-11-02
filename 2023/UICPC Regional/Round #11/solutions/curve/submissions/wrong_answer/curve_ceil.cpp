#include <cmath>
#include <cstdint>
#include <iostream>

using namespace std;

constexpr double EPS = 1e-9;

int main() {
    double R, S;
    while (cin >> R >> S) {
        double V = sqrt(R * (S + .16) / 0.067);

        cout << static_cast<int64_t>(V + 1.0 - EPS) << '\n';
    }
    return 0;
}
