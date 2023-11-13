#include <iostream>
#include <cstdio>

using namespace std;

int n, p;
double x, u;

int main() {
    cin >> n >> p;
    x = u = (double)p/(n+1);
    for (int k = 1; k <= 1000000; k++) {
        x *= (k+1);
        x /= k;
        x *= (n+k+1-p);
        x /= (n+k+1);
        u = max(x,u);
    }
    printf("%.9f\n", u);
}
