#include <iostream>
#include <cmath>

using namespace std;

int  main() {
    long long int  n;
    cin >> n;
    for (long long int  i = 0; i < n; i++) {
        long long int  t;
        cin >> t;
        long long int  y = 0;
        if( t == 2){
            cout << 0 << endl;
            continue;
        }
        for (long long int  j = 2; j <= t; ++j) {
            long long int  ch = 0;
            for (long long int  k = 2; k <= sqrt(j); ++k) {
                if (j % k == 0) {
                    ch++;
                    break;
                }
            }
            if (ch == 0 && (j * 2) > t) {
//                cout << j << endl ;
                y++;
            }
        }
        cout << y << endl;
    }
}
