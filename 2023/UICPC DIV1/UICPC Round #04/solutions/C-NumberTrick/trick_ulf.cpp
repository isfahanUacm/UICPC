#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;

const double eps = 1e-5;

int main() {
    double X;
    cin >> X;
    ll P = 1;
    bool empty = true;
    for (int k = 0; k < 8; ++k) {
        for (int d0 = 1; d0 < 10; ++d0) {
            ll A = d0*(P*10-1)/(10-X)+.5;
            if (A/P == d0 && abs((A-d0*P)*10+d0 - X*A) < eps) {
                cout << A << endl;
                empty = false;
            }
        }
        P = P*10;
    }
    if (empty)
        cout << "No solution" << endl;
}