#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int j = 0; j < t; j++) {
        int n, C;
        cin >> n >> C;
        int c[n];
         for (int k = 0 ; k < n; k++) {
             cin >> c[k];
         }
         int tmp = C, res = 1;
         for (int m = 0 ; m < n; m++) {
             if (c[m] < tmp) {
                 tmp -= c[m];
             } else {
                 tmp = C;
                 res++;
             }
        }
        cout << res << endl;
    }
}